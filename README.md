# Semseterser

[![Build Status](https://travis-ci.org/Semseterser/Semseterser.svg?branch=master)](https://travis-ci.org/Semseterser/Semseterser)

## Development
To build the project:
```bash
git clone https://github.com/Semseterser/Semseterser.git
cd Semseterser
mkdir build
cmake .. && make
```
In order to keep the development of semseterser as consistent as possible,
some of the core libraries are fetched and compiled automatically during the
build phase. See [Dependencies](#Dependencies) to find out requirements for building
the libraries.

## Dependencies

For SFML:
* pthread
* opengl
* xlib
* xrandr
* udev
* freetype
* openal
* flac
* vorbis

In case of a build failure, check [the SFML website](https://www.sfml-dev.org/faq.php#grl-dependencies) for any missing dependencies.
