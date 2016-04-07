Atria
=====

*Atria is a toolkit for modern C++ development*.

[![Build Status](https://travis-ci.org/Ableton/atria.svg?branch=master)]
(https://travis-ci.org/Ableton/atria)

It provides core components that extend the standard library
capabilities.  It provides various libraries of general interest, in
the spirit of the STL, Boost, Adobe Source Libraries, or Facebook's
Folly and Fatal.

This is an **open source** project.  You're encouraged to use it,
modify it, and redistribute it.

Status
------

Atria is written in **standard C++11** and compiles with recent
versions of GCC and Clang.

This project is under active development and its API is not stable
yet.  Thus it is not suitable for most production systems.  However it
is thoroughly tested, and **we encourage you to try it**.  Your
feedback is very welcome.

## Modules

* `atria::prelude` provides basic functional programming tools in the
  spirit of those in Clojure `core` and Haskell's `Prelude`.

* `atria::variant` provides tools for better usability of
  [Boost.Variant](http://www.boost.org/doc/libs/1_58_0/doc/html/variant.html)
  and [Eggs.Variant](http://eggs-cpp.github.io/variant/) and is
  customizable to other sum type implementations.

* `atria::meta` provides several metaprogramming tools, including some
  [Boost.MPL](http://www.boost.org/doc/libs/1_59_0/libs/mpl/doc/index.html)
  adaptors for several variadic types and concept checking facilities.

* `atria::estd` provides C++11 compatible implementations of some
  C++14 and beyond standard library components.

* `atria::xform` provides an efficient C++ implementation of
  transducers, a concept introduced in
  [Clojure](http://blog.cognitect.com/blog/2014/8/6/transducers-are-coming)
  by Rich Hickey.

* `atria::funken` provides a *experimental* library for writing epochal
  and functional data-models.

* `atria::testing` provides testing tools and frameworks for writing
  spies, mocks, micro-benchmarks and more.

## Documentation

**Reference documentation**
[can be browsed here](http://ableton.github.io/atria/reference).

It can be generated by executing in the project directory: `doxygen doxy/doxygen.config`

### Talks

- [We will talk about parts of the library in CppCon 2015](
http://cppcon2015.sched.org/event/ff8f576d5d0fe02bcc05fccfa56359a3)

## Dependencies

  - [boost](http://www.boost.org/doc/libs/1_59_0)
  - [googletest](https://chromium.googlesource.com/external/googletest) (for testing only)

Other dependencies are vendored via submodules.  Make sure to run `git
submodule update --init --recursive` before building.

## Maintainers

- Juan Pedro Bolívar Puente ([`@arximboldi`](https://github.com/arximboldi))
- Tobias Hahn ([`@toh-ableton`](https://github.com/toh-ableton))
- Stephan Bots ([`@sbs-ableton`](https://github.com/sbs-ableton))

License
-------

**Atria** is distributed under the MIT license (see LICENSE).

> Copyright (c) 2014, 2015 Ableton AG, Berlin
>
> Permission is hereby granted, free of charge, to any person obtaining a copy
> of this software and associated documentation files (the "Software"), to deal
> in the Software without restriction, including without limitation the rights
> to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
> copies of the Software, and to permit persons to whom the Software is
> furnished to do so, subject to the following conditions:
>
> The above copyright notice and this permission notice shall be included in
> all copies or substantial portions of the Software.
>
> THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
> IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
> FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
> AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
> LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
> OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
> THE SOFTWARE.
