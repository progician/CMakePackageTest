CMake Packaging Test
====================

This project is a simple demonstration how a composition of C++ libraries and and executable can be constructed using CMake.

Overview
--------

There are 3 projects in this repository:

1. Foo: A static library containing a single function.
2. SharedGoodies: A shared library that handles exporting of a single class.
3. Bar: The executable that links together the libraries above.


The Idea
--------

A good composition of independent packages can make a huge difference on the architecture of a larger project. It is tempting to construct a project out of a number of libraries and other moving parts in a single monolithic build, it will inevitably muddled in its dependency graph and becomes unmaintainable as well as difficult to build.

Instead, one can choose to decompose such a monolithic monster into simple well manageable packages. The idea behind is that you can build each of these packages in isolation, installing only their respective dependencies and thus it could be composed easily together into a single distribution at the end product.
