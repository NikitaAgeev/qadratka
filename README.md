# Qadratka
This is a program that solves quadratic equations with full processing of all possible errors.
## How to build
To build a project, you need to write `make` in the root folder of the project.
After the build, a `\progect` will be created in which the executable file (`Qadratca_1.00`) is located

To delete a project, you need to write `make clean`

## How to use
To run, you need to pass the coefficients of the quadratic equation as a command-line argument.

### Supported equation formats

1. The quadratic equation

    * equation format
    `ax^2 + bx + c = 0`

    * Input format 
    `./[executable_file] a b c`

2. Linear equation

    * equation format
    `ax + b = 0`

    * Input format 
    `./[executable_file] a b`

### Other functionality
1. You can enter the argument `help` for help
2. You can enter the argument `test` for unit testing
