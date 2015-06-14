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

Missing features (in development):
- Use double / GMP
- In command line:
-   If no argument: launch as a bash for calculation (waiting for "exit" command)
-   If no argument: "functions" command: show the list of function
-   If arguments: calculate every argument and exit automatically
-   If argument = -f / --available-functions: show the list of function (cancel remaining calculations)

Code
- Use references when possible
- Comments
- Application class to manage command line
