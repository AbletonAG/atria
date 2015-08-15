// Copyright: 2014, 2015, Ableton AG, Berlin. All rights reserved.
/*!
 * @file
 */

#pragma once

#include <atria/xform/transducer_impl.hpp>
#include <atria/xform/state_wrapper.hpp>
#include <atria/xform/with_state.hpp>
#include <atria/xform/skip.hpp>
#include <atria/prelude/tuplify.hpp>
#include <atria/estd/type_traits.hpp>

namespace atria {
namespace xform {

namespace detail {

struct dedupe_rf_gen
{
  template <typename ReducingFnT>
  struct apply
  {
    ReducingFnT step;

    template <typename StateT, typename ...InputTs>
    auto operator() (StateT&& s, InputTs&& ...is)
      -> decltype(wrap_state(step(state_unwrap(s), is...), tuplify(is...)))
    {
      using result_t   = decltype(wrap_state(step(state_unwrap(s), is...), tuplify(is...)));
      using complete_t = decltype(state_complete(s));

      using wrapped_t   = meta::copy_decay_t<StateT, estd::decay_t<result_t>>;
      using unwrapped_t = meta::copy_decay_t<StateT, estd::decay_t<complete_t>>;

      return with_state(
        std::forward<StateT>(s),
        [&] (unwrapped_t&& st) {
          auto last = tuplify(is...);
          return wrap_state(
            step(state_unwrap(std::forward<unwrapped_t>(st)),
                 std::forward<InputTs>(is)...),
            std::move(last));
        },
        [&] (wrapped_t&& st) {
          auto next = tuplify(is...);
          auto dupe = next == state_wrapper_data(st);
          return dupe
            ? std::forward<wrapped_t>(st)
            : wrap_state(
              step(state_unwrap(std::forward<wrapped_t>(st)),
                   std::forward<InputTs>(is)...),
              std::move(next));
        });
    }
  };
};

} // namespace detail

using dedupe_t = transducer_impl<detail::dedupe_rf_gen>;

/*!
 * Equivalent to clojure/dedupe$0
 */
constexpr dedupe_t dedupe {};

} // namespace xform
} // namespace atria
