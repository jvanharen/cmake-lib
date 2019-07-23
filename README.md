[![Build Status](https://travis-ci.org/jvanharen/cmake-lib.svg?branch=master)](https://travis-ci.org/jvanharen/cmake-lib)

# Modern [CMake](https://cmake.org) example for a C library

# Overview

This example shows how to build a library with modern [CMake](https://cmake.org) and several useful features.

# Features

-   Build an example library
-   Export the library targets to be usable by other projects
-   Can build several programs based on this library
-   Install this library with headers
-   [Unity](http://www.throwtheswitch.org/unity/) integration to write unit tests
-   [CTest](https://cmake.org) integration to automate tests
-   [CPack](https://cmake.org) integration to distribute a \*.tar.gz package
-   [Valgrind](http://valgrind.org) integration for memory leaks check (Linux only)
-   [Clang-format](https://clang.llvm.org/docs/ClangFormat.html) integration to format the code
-   Version integration in the C source code
-   [Git](https://git-scm.com) branch integration in the C source code
-   [Git](https://git-scm.com) commit integration in the C source code
-   Documentation integration with [Doxygen](http://www.doxygen.nl)/[Breathe](https://breathe.readthedocs.io/en/latest/)/[Sphinx](http://www.sphinx-doc.org/en/master/)

# Installation

### Download the sources:

```bash
git clone https://github.com/jvanharen/cmake-lib
cd cmake-lib
git submodule update --init --recursive
```

### CMake configuration:

```bash
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/path/to/install -DBUILD_SHARED_LIBS=ON -DCMAKE_BUILD_TYPE=Release -DBUILD_DOC=ON -DCLANGFORMAT=ON ..
```

The available CMake options are:

-   \-DBUILD_SHARED_LIBS=[ON/OFF] for building shared library or not
-   \-DBUILD_DOC=[ON/OFF] for building the documentation or not
-   \-DCLANGFORMAT=[ON/OFF] for adding a target to indent all the source code

### Build with CMake:

```bash
make
```

### Run the tests:

```bash
make test
```

### Indent all the source files:

```bash
make clangformat
```

### Generate the documentation:

```bash
make doc
```

### Create a package:

```bash
make package
```

### Run Valgrind to check the memory leaks (Linux only):

```bash
ctest -D ExperimentalMemCheck
```

# Tree

```bash
.
├── CMakeLists.txt ──────────────────────── Mandatory
├── LICENSE ─────────────────────────────── Mandatory
├── README.md ───────────────────────────── Mandatory
├── cmake ───────────────────────────────── Mandatory
│   ├── FindClangFormat.cmake
│   ├── FindSphinx.cmake
│   └── Findargp.cmake
├── doc ─────────────────────────────────── Optional
│   ├── CMakeLists.txt
│   ├── Doxyfile.in
│   ├── conf.py.in
│   ├── index.rst
│   └── src
│       ├── doc_src1.rst
│       └── doc_src2.rst
├── include ─────────────────────────────── Mandatory
│   └── library_name ────────────────────── Mandatory
│       └── library_name.h ──────────────── Mandatory (Public library header)
├── prg ─────────────────────────────────── Optional
│   ├── CMakeLists.txt
│   ├── prg1.c
│   └── prg2.c
├── src ─────────────────────────────────── Mandatory
│   ├── CMakeLists.txt ──────────────────── Mandatory
│   ├── library_src1.c
│   ├── library_src2.c
│   └── version.h.in ────────────────────── Mandatory
└── test ────────────────────────────────── Optional
    ├── CMakeLists.txt
    ├── test1.c
    ├── test2.c
    └── unity
```
