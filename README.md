# konvertjson

### TODOs

This is a WIP project, some ideas to be examined:

+ Include Travis + license scan
+ See the templates already done by *tista (see my notes)
+ Split up the current template in two: one for Optional, another for no optional (mandatory)
+ Return pair (all return values there) vs return boolean (just return a bool for a more fluent API, and
  return other output arguments as part of the function call arguments)
+ Return a bool + err description
+ Validate callback to do extra work and return value as : return ParseReturn || ValidateReturn
+ I am just managing builtins + optional builtins. Next step is vector of builtins + optional vector
+ See the 'High order Perl ideas': list of 'things to do' to fix the recursion pattern
+ 'likely' and 'unlikely' optimizatoins (with parameter to be use as a hint?)
+ Name the current functions with 'builtin'
+ Use the libraries for C++ introspection (see my notes) to walk through the fields of the struct
+ Explain the dependency with rapidjson

konvertjson is a minimal project that's kept deliberately very small.
When you build it using CMake/make (see below) it generates:

 1. A tiny **static library** `lib/libdivision.a`,
 2. **A command line binary `bin/divider`**, which links with the library,
 3. **An executable unit test** `bin/divider_tests`  using [Google Test library](https://github.com/google/googletest).
 4. **An optional BASH build script** `build-and-run` that you can use to quickly test if the project compiles, and runs.

## Usage

$ cmake .

$ make -j12 && make install (this install stuff under '/bin/')

## Running the tests

$ ./bin/divider_tests

## Prerequisites

You will need:

 * A modern C/C++ compiler
 * CMake 3.1+ installed

### Building The Project

#### Git Clone

First, we need to check out the git repo:

```bash
❯ mkdir ~/workspace
❯ cd ~/workspace
❯ git submodule update --init --recursive
❯ git clone https://github.com/rauhersu/konvertjson
❯ cd my-project
❯ bash build-and-run
```
The script `build-and-run` is a short-cut — you shouldn't really be using this script to build your project.

#### Project Structure

There are three empty folders: `lib`, `bin`, and `include`. Those are populated by `make install`.

The rest should be obvious: `src` is the sources, and `test` is where we put our unit tests.

Now we can build this project:

#### Building Manually

```bash
❯ rm -rf build && mkdir build
❯ git submodule update --init --recursive
❯ cd build
❯ cmake ..
❯ make && make install
❯ cd ..
```

## File Locations

 * `src/*` — C++ code that ultimately compiles into a library
 * `test/lib` — C++ libraries used for tests (eg, Google Test)
 * `test/src` — C++ test suite
 * `bin/`, `lib`, `include` are all empty directories, until the `make install` install the project artifacts there.

Tests:

 * Tests compile into a single binary `test/bin/runner` that is run on a command line to run the tests.
 * `test/lib` folder with a git submodule in `test/lib/googletest`, and possibly other libraries.

#### Contributing

**Pull Requests are WELCOME!** Please submit any fixes or improvements, and I promise to review it as soon as I can at the project URL:

 * [Project Github Home](https://github.com/rauhersu/konvertjson)
 * [Submit Issues](https://github.com/kigster/rauhersu/konvertjson)
 * [Pull Requests](https://github.com/kigster/rauhersu/konvertjson)

### License

&copy; 2021 Raúl Hernández.

Open sourced under MIT license, the terms of which can be read here — [MIT License](http://opensource.org/licenses/MIT).

### Acknowledgements

This project uses the [CMake Tutorial](https://cmake.org/cmake-tutorial/), and the [cmake-project-template](https://github.com/kigster/cmake-project-template).
