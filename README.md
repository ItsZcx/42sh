# 42sh

This repository contains the final branch project at Epitech, an UNIX shell implementation with various POSIX builtins.

## Usage

```
make
./42sh
```

## Features

- **Builtins:**
  - `cd [path]`
  - `echo [str]`
  - `exit [num]`
  - `env`
  - `setenv [var_name] [var_value]`
  - `unsetenv [var_name]`
  - `alias [alias_name] [str]`
  - `history [event_designators]`
  - `which [bin_name]`
  - `where [bin_name]`

- **Complex commands:**
  - The following redirections: ">", "<<", ">>", "<".
  - Pipes "|".
  - Logical operators "&&" and "||".
  - The ";" separator.

- **Exit signals:**
  - Ctrl + D
  - Ctrl + C

- **Structure:**
  - Initialization
  - Edit input
  - Break input
  - Parse input
  - Word expansion
  - Redirect
  - Execution
  - Wait

## Unit testing

Make sure that before trying to test the the binary you have [Criterion](https://criterion.readthedocs.io/en/master/index.html), [gcovr](https://gcovr.com/en/stable/) installed and the binary COMPILED [make].
```
make tests_run
```
Will create the necessary object files and run the tests. After usage you can remove them by using:
```
make fclean
```

## License

This project is licensed under the [MIT License](LICENSE).