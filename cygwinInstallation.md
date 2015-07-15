
# cygwinInstallation v1.0

This file explains how to install the mpfr library on cygwin, so that the program can be compiled to be normally executed on Windows (and not from Cygwin terminal).
In order to do that, the mpfr and the gmp libraries must be compiled and installed.

### GMP library:

##### Download and preparation
- `mkdir gmp`
- `cd gmp`
- `wget https://gmplib.org/download/gmp/gmp-6.0.0a.tar.bz2` or download from mpfr library website: https://gmplib.org/#DOWNLOAD (take the .tar.bz2 version)
- `tar -vxjf gmp-6.0.0a.tar.bz2`
- `mkdir gmp-6.0.0_build`

##### Compilation and installation
- `cd gmp-6.0.0_build`
- `../gmp-6.0.0/configure CC=x86_64-w64-mingw32-gcc`
- `make`
- `make install`

### Mpfr library:

##### Download and preparation
- `mkdir mpfr`
- `cd mpfr`
- `wget http://www.mpfr.org/mpfr-current/mpfr-3.1.3.tar.bz2` or download from mpfr library website: http://www.mpfr.org/mpfr-current/#download (take the .tar.bz2 version)
- `tar -vxjf mpfr-3.1.3.tar.bz2`
- `mkdir mpfr-3.1.3_build`

##### Compilation and installation
- `cd mpfr-3.1.3_build`
- `../mpfr-3.1.3/configure CC=x86_64-w64-mingw32-gcc --with-gmp-include=/usr/local/include --with-gmp-lib=/usr/local/lib --enable-static --disable-shared`
- `make`
- `make install`

### Compilation of calculator
- The libraries are now installed.
- The compilation can be done by specifying the library and include paths to the configure script.
- The `-static-libgcc` and `-static-libstdc++` flags should be specified to avoid the need of DLLs. On the other hand, the executable size gets bigger.
  * `../calculator/configure CXX=x86_64-w64-mingw32-g++ CXXFLAGS="-static-libgcc -static-libstdc++ -I/usr/local/include" LIBS="-L/usr/local/lib -lmpfr -lgmp"`
  * `make`

### Copyright
Copyright 2015 Yann Kurzo. All rights reserved.
This project is released under the GNU Public License (see LICENSE file).
