````markdown
*This project has been created as part of the 42 curriculum by <meridbel>.*

# Description

**push_swap** is a project designed to sort a stack of integers using a limited set of operations.  
The goal is to generate the shortest possible sequence of instructions to sort any given list of integers.  
It helps improve algorithmic thinking, understanding of stack manipulation, and efficiency optimization in C programming.

# Instructions

## Compilation

```bash
make
````

This will generate the executable `./push_swap`.

## Execution

Run the program by passing integers as arguments:

```bash
./push_swap 2 1 3 6 5
```

The program outputs a series of operations (`sa`, `ra`, `rra`, `pb`, `pa`, etc.) to sort the stack.

You can verify the result with the `checker` program:

```bash
./push_swap 2 1 3 6 5 | ./checker_linux 2 1 3 6 5
```

If the stack is sorted correctly, `checker` will print `OK`; otherwise, it will print `KO`.

# Resources

* [C Programming Documentation](https://man7.org/linux/man-pages/man3/)
* [Stack Data Structure](https://en.wikipedia.org/wiki/Stack_%28abstract_data_type%29)

**AI Usage:**
AI was used to clarify algorithm logic, help explain concepts related to linked lists, stacks, and algorithmic logic.

# Additional Notes

* The program handles 2 to N integers.
* Input validation checks for duplicates and non-integer values.
* Small stacks (≤5 numbers) are sorted with dedicated functions.
* Larger stacks use a chunk-based algorithm to minimize operations.

```
