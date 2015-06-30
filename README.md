
# calculator v1.0

This program can parse a string entered by the user. It calculates the mathematical result of the string. The program can be configured at compilation time by modifying the config.h file. By default, it uses double type to make calculation. It is possible to use the mpfr library to do the calculation, so that the precision can be defined by the user and that it can be much larger than a double precision.

### Working features:
- Numbers
- Operators (+,-,*,/,^,%, unary minus -)
- Operator priority
- Brackets
- Functions
- Check entered string (function parameters, operation without operators, bracket problems, ...) (not perfect)
- Argument mode
  * "calculator "2*5" "2+8"" (multiple calculation in a row, use quotation marks)
  * "calculator -h" (shortcut argument)
  * "calculator --help" (full argument)
- Command mode
  * 2*5 2+8 (multiple calculation in a row, separated by spaces)
  * "-h" command (shortcut command)
  * "help" command (full command)
- Use the help command to get a list of available commands
- Calculation using double type or mpfr library (see config.h file)

### Missing features (in development):
- Add save / restore with =
- Implicit multiplication (Ex: 2(4+3) == 2*(4+3) || 2pi() == 2*pi() )

### Compilation
- This program uses the autoconf / automake tool for the compilation.
- To be able to compile, the following tools are necessary:
  * a UNIX like environment (Linux / cygwin for Windows)
  * the "make" command
- For the compilation, run the following commands:
  * ./configure
  * make
  * make install
- Help can be found by using:
  * ./configure --help
- Getting the mpfr library (this library is only necessary for compiling for big numbers)
  * Linux: http://www.mpfr.org/mpfr-current/#download
  * Cygwin: https://cygwin.com/install.html (use the setup to install the library)

### Code corrections
- String error detection:
  * "+4" => Core dump

### Doc
- Doxygen

### Copyright
Copyright 2015 Yann Kurzo. All rights reserved.
This project is released under the GNU Public License (see gpl-3.0.txt).
