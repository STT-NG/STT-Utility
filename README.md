# STTUtil

A small library for interfacing with the GeomRel library. Adds support for ingesting geometry descriptions from various straw-tube trackers.

## Usage

With CMake: Simply clone the repository and call `addsubdirectory(path/to/repo)` to have access to the header files in your project.

## Extending The Library

To add support for your own straw-tube tracker, place the code needed to ingest your geometry description into a single header file with a reasonable name so the STT type is recognizable. Add an `#include` statement for your header in the main `util.h` file and you're done!

If you want you can then make a PR with the new file to allow others to interface with your STT. Please stick to only one file.
