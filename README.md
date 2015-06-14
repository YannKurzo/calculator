# calculator v1.0

This program can parse a string entered by the user. It calculates the mathematical result of the string.

Working features:
- Numbers
- Operators (+,-,*,/,^,%, unary minus -)
- Operator priority
- Brackets
- Functions
- Implicit multiplication (Ex: 2(4+3) == 2*(4+3) || 2pi() == 2*pi() )
- Check entered string (function parameters, operation without operators, bracket problems, ...) (not perfect)
- Argument mode
  * "calculator 2*5 2+8" (multiple calculation in a row)
  * "calculator -l" (show function list)
  * "calculator --list-available-functions" (show function list)
- Command mode
  * 2*5 (single calculation at a time)
  * "list-available-functions" command (show function list)
  * "-l" command (show function list)
  * "exit" to quit

Missing features (in development):
- Use double / GMP

Commands to add
- 

Code
- Correct indent
- Comments
