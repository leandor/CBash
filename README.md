# CBash

**DISCLAIMER**: Keep in mind that binaries produced from this code aren't compatible yet with the current Wrye Bash _(current means: the 'dev' branch on Wrye-Bash here.)_ The incompatibility lies in some changes to published functions that broke the API provided to `cint.py`.

CBash is a C/C++ library for reading and writing TES IV: Oblivion, TES V: Skyrim and Fallout: New Vegas plugin files. It's used by the [Wrye Bash](https://github.com/wrye-bash/wrye-bash) modding utility to build its Bashed Patch plugins.

For bugs and feature request, feel free to open a new Issue in the Issue tracker.  For other discussions, open a new thread [here](http://ost.io/@lojack5/CBash "ost.io"), for example asking questions about what specific parts of the code do, etc.

Instructions on how to build CBash can be found [here](docs/BUILD.md). If linking to a static build of CBash, be sure to define `CBASH_STATIC`. Otherwise, if linking to a dynamic build, define `CBASH_DLL`.

The plugin file formats are documented at the following locations:

* Oblivion: [UESP.net](http://www.uesp.net/wiki/Tes4Mod:Mod_File_Format)
* Skyrim: [UESP.net](http://www.uesp.net/wiki/Tes5Mod:Mod_File_Format)
* Fallout: New Vegas: [FOPDoc](https://github.com/WrinklyNinja/fopdoc)

The CBash API is currently sparsely documented. There is some Doxygen-style documentation of the API in the [include headers](include/cbash).

CBash's record and field support is incomplete. For information on what has and has not ben implemented, see the [wiki](https://github.com/wrye-bash/CBash/wiki).

This repository was created from the [current state](https://github.com/lojack5/CBash/commit/1f90085a27c6847685d6eb9589a1d7fda5c85862) (as of 10/15/2016) of Lojack's [CBash repository](https://github.com/lojack5/CBash).

The WIKI content is still to be ported, so use the [original location](https://github.com/lojack5/CBash/wiki) until we are finished with the move.
