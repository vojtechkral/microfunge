MicroFunge
===

MicroFunge is a minimalist BeFunge-93 interpreter.
(See [Wikipedia](https://en.wikipedia.org/wiki/Befunge) if you don't know BeFunge.)
I wrote it just for fun, to see if I could stuff a BeFunge interpreter in a 25x80 C++ code.

While being a C++ source, the microfunge.cpp file is also a fully working BeFunge-93 quine program.

Even though it's so minimalist, it should be reasonablyfast and standard-compliant.

MicroFunge requires a fairly recent C++ compiler - some C++11 features are used.

I am not certain the code compiles well and all platforms, there may be a structure
padding problem.
