# Cmake Template

## Live coding interview for Shopify engineer postition

Problem (Sample output and explanation)


Create a command line app that prompts for commands and moves a rover around a 2D plane.
The robot should point in a direction, turn to face different directions, and move in the direction it is facing.

Hello! Robot coming online.
Command the robot with:
  L - turn left
  R - turn right
  M - move forward
  ? - this message
  Q - quit
> M
Robot at (0, 1) facing North
> L
Robot at (0, 1) facing West
> M
Robot at (-1, 1) facing West
> M
Robot at (-2, 1) facing West
> L
Robot at (-2, 1) facing South
> M
Robot at (-2, 0) facing South
> R
Robot at (-2, 0) facing West
> R
Robot at (-2, 0) facing North
> R
Robot at (-2, 0) facing East
> M
Robot at (-1, 0) facing East
> ?
Command the robot with:
  L - turn left
  R - turn right
  M - move forward
  ? - this message
  Q - quit
> Q
Robot shutting down.



## About

- Supports Clang, GNU, and MSVC toolchains (Compiles on Linux, MacOS and Windows out of the box).
- Uses clang-format with Microsoft style.
- Setup in a workspace style, where the top level CMakeLists.txt delegates lower level cmake files to clearly seperate shared/static libraries and exectubles. Great for mono repos.
- All static analyzers/tooling is setup (clang-tidy, cpp-check, include what you use) as well as santizers.
- Uses [CPM](https://github.com/cpm-cmake/CPM.cmake) for package management.
- Uses the googletest unit-testing/mocking library.
- Utilizes a `.vscode/tasks.json` for compiling and running tests, and a `.vscode/launch.json` for debugging. VScode, Neovim, and Emacs can all use these files. (The two latter have plugins).

## Usage

### Use the Github template

First, click the `Use this template` button at the top of this page.

### Additional Details

1. Read [this](./docs/make_it_your_own.md) for CMake variables you will need to change to conform the template to your project.
2. Read [this](./docs/dependencies.md) for host platform dependencies
3. Read [this](./docs/building.md) for building instructions

## License

MIT © Matt Williams
