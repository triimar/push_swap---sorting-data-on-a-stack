# push_swap---sorting-data-on-a-stack

### Overview

The goal of `push_swap` is to sort data on a stack with a limited set of instructions, using the lowest possible number of actions. This project involves sorting two stacks, `a` and `b`, where stack `b` starts and finishes empty, and stack `a` starts with unsorted integers and ends up sorted.

### Actions

- `sa` (swap a): Swap the first 2 elements at the top of stack a.
- `sb` (swap b): Swap the first 2 elements at the top of stack b.
- `ss` : sa and sb at the same time.
- `pa` (push a): Take the first element at the top of b and put it at the top of a.
- `pb` (push b): Take the first element at the top of a and put it at the top of b.
- `ra` (rotate a): Shift up all elements of stack a by 1.
- `rb` (rotate b): Shift up all elements of stack b by 1.
- `rr` : ra and rb at the same time.
- `rra` (reverse rotate a): Shift down all elements of stack a by 1.
- `rrb` (reverse rotate b): Shift down all elements of stack b by 1.
- `rrr` : rra and rrb at the same time.

### Themes

- Sorting algorithms
- Battery concept and handling elements
- Algorithm implementation

### Bonus

The `bonus` feature includes a `checker` for `push_swap`, a program that validates the actions listed by `push_swap`.


### Running the Program(s)

- **./push_swap \<input integers separated with spaces\>**: Runs the sorting algorithm.

- **./checker \<input integers separated with spaces\>**: Validates the sorting actions and returns success or failure.

- **ARG="\<input integers separated with spaces\>"; ./push_swap $ARG | ./checker**: Runs both the sorter and the checker together.


I strongly recommend running `push_swap` with the [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer) to better understand what is happening.


https://github.com/triimar/push_swap---sorting-data-on-a-stack/assets/116010422/161a6997-9682-430b-a151-b5cb77be4776

