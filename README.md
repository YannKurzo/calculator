
# calculator v1.0

This program can parse a string entered by the user. It calculates the mathematical result of the string. The program can be configured at compilation time by modifying the config.h file. By default, it uses double type to make calculation. It is possible to use the mpfr library to do the calculation, so that the precision can be defined by the user and that it can be much larger than a double precision.

### Working features:
- Numbers
- Operators (+,-,\*,/,^,%, unary minus -, implicit multiplication [2pi => 2\*pi])
- Operator priority
- Brackets
- Basic mathematical functions
- Some basic constants
- Saving results in temporary variables
- Use the help command to get a list of available commands
- Calculation using double type or mpfr library (see config.h file)
- When using mpfr library, it is possible to define the precision (the number of bits of the mantissa). It is useful not only for high precision, but also for checking how the coding of the floating point numbers work.
- Check entered string (function parameters, operation without operators, bracket problems, ...) (not perfect)
- History of commands accessible with keyboard arrows (compatible with Windows and Posix systems)

##### Argument mode
The program can be launched from a command line with multiple parameters. It will displays all the results separated by spaces and then automatically quit the program.
 - Use:
  * "calculator "2*5" "2+8"" (multiple calculation in a row, use quotation marks)
  * "calculator -h" (shortcut command)
  * "calculator --help" (full command)
 
##### Command mode
The program can be launched without parameters. It will then work as a bash and execute each calculation entered by the user without quitting the program. To quit, the "-q" command (or "--exit") can be used.
 - Use:
  * 2*5 (one calculation at a time)
  * "-h" command (shortcut command)
  * "--help" command (full command)

### Compilation and installation
##### Compilation
- To be able to compile, the following tools are necessary:
  * a UNIX like environment (Linux / cygwin for Windows)
  * the "make" command
- For the compilation, run the following commands:
  * clone "https://github.com/YannKurzo/calculator.git"
  * mkdir calculator_build
  * cd calculator_build
  * ../calculator/configure
  * make
##### Installation
- On Linux
  * make install
- On Windows
  * The executable is located in calculator_build/src/calculator.exe
##### Compilation on Windows to be able to launch outside Cygwin

##### Help
- Help can be found by using:
  * ./configure --help
- Getting the mpfr library (this library is only necessary for compiling for big numbers)
  * Linux: http://www.mpfr.org/mpfr-current/#download
  * Cygwin: https://cygwin.com/install.html (use the setup to install the library)
- This program uses the autoconf / automake tools for the compilation.

### Missing features (in development)
- Power operator priority 2^3^2 => 2^(3^2)

### Code corrections
- Bug when displaying values of constants and user defined variables
- Bug when writing "constant="

### Doc
- Doxygen

### Copyright
Copyright 2015 Yann Kurzo. All rights reserved.
This project is released under the GNU Public License (see LICENSE file).
