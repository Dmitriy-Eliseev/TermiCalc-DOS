# TermiCalc [DOS version]
Simple console calculator with trigonometric functions.

The same as [TermiCalc](https://github.com/Dmitriy-Eliseev/TermiCalc), but compatible with DOS. An adapted version ([TinyExpr-C89](https://github.com/Dmitriy-Eliseev/TinyExpr-C89)) is used instead of the original TinyExpr library.

## Compilation (Open Watcom)
```
wcl -3 -ox -s -fe=TCALC.EXE TERMCLC.C TINYEXPR.C
```
## Usage
```
TCALC.EXE [expression ...]
```
```
TCALC.EXE [expression1] [expression2] [expression ...]
```
```
TCALC.EXE
```
If no expressions are specified, the program runs interactively and accepts expressions from the keyboard. To exit interactive mode, enter q.

If one or more expressions are specified, the program calculates them and displays the results on the screen.

To get help on the program, use one of the following parameters: "help", "--help", "h", "?" or enter "h" or "?" to the interactive mode line.
### Usage examples
![usage examples](https://raw.githubusercontent.com/Dmitriy-Eliseev/TermiCalc-DOS/refs/heads/main/usage_examples.png)
