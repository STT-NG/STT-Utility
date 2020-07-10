# STTUtil

A small library for interfacing with the GeomRel library. Adds support for ingesting geometry descriptions from various straw-tube trackers.

## Usage

With CMake: Simply clone the repository and add a call to `add_subdirectory(path/to/repo)` to have access to the header files in your project.

Without CMake: add the header files directly to your include directory. Or your sources if you're so inclined.

In either case you can import the library using `#include<STTUtil>`

## Extending The Library

To add support for your own straw-tube tracker, place the code needed to ingest your geometry description into a single header file with a reasonable name so the STT type is recognizable. Add an `#include` statement for your header in the main `util.h` file and you're done!

Refer to the implementation for the PANDA STT in `panda.h` for an example of how you could add support for your STT.

If you want you can then make a PR with the new file to allow others to interface with your STT. Please stick to only one file.
