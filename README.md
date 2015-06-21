
# calculator v1.0

This program can parse a string entered by the user. It calculates the mathematical result of the string. The program can be configured at compilation time by modifying the config.h file. By default, it uses double type to make calculation. It is possible to use the mpfr library to do the calculation, so that the precision can be defined by the user and that it can be much larger than a double precision.

### Working features:
- Numbers
- Operators (+,-,*,/,^,%, unary minus -)
- Operator priority
- Brackets
- Functions
- Implicit multiplication (Ex: 2(4+3) == 2*(4+3) || 2pi() == 2*pi() )
- Check entered string (function parameters, operation without operators, bracket problems, ...) (not perfect)
- Argument mode
  * "calculator 2*5 2+8" (multiple calculation in a row)
  * "calculator -h" (shortcut argument)
  * "calculator --help" (full argument)
- Command mode
  * 2*5 (single calculation at a time)
  * "-h" command (shortcut command)
  * "help" command (full command)
- Argument and commands
  * Use help to get a list
  * Actual list: exit, list-available-functions, help
- Calculation using double type or mpfr library (see config.h file)

### Missing features (in development):
- Add usual constants in external functions

### Code corrections

### Doc
- Doxygen

### Copyright
Copyright 2015 Yann Kurzo. All rights reserved.
This project is released under the GNU Public License (see gpl-3.0.txt).
