# push_swap

*Part of the 42 Lisboa common core.*

`push_swap` sorts a list of integers using two stacks (**a** and **b**) and a fixed set of 11 operations, and it tries to use as few operations as it can. The program prints the list of operations that sorts the input.

## Operations

| Op | Effect |
| --- | --- |
| `sa` / `sb` / `ss` | swap the top two elements of a / b / both |
| `pa` / `pb` | push the top of b onto a / the top of a onto b |
| `ra` / `rb` / `rr` | rotate up: the first element becomes the last |
| `rra` / `rrb` / `rrr` | rotate down: the last element becomes the first |

## Build

```sh
make        # builds ./push_swap
make clean / fclean / re
```

## Usage

```sh
./push_swap 3 2 5 1 4
./push_swap "3 2 5 1 4"                       # one quoted string also works
ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l
```

Invalid input (non-integers, duplicates, values outside `int`) prints `Error` on stderr.

## Algorithm

- **3 numbers or fewer**: hard-coded cases, at most 2 operations.
- **More than 3**: a cost-based ("Turk") approach.
  1. Push everything except 3 elements to **b**, then sort the 3 left in **a**.
  2. For each node in **b**, find its target position in **a**, then the cost of rotating both stacks there. Rotations go up or down depending on which side of the median each node is on, and shared rotations (`rr` / `rrr`) are combined.
  3. Push back the **cheapest** node, then repeat until **b** is empty.
  4. Rotate **a** until its smallest value is on top.

Over 20 random runs, the worst case was 680 operations for 100 numbers and 6,131 for 500.

## Layout

| Path | Purpose |
| --- | --- |
| `src/main.c`, `src/handle_args.c`, `src/split.c` | Argument parsing and validation |
| `src/init_nodes.c`, `src/target.c`, `src/push_price.c` | Targets, median flags and move costs |
| `src/core.c`, `src/aux_core.c` | The sorting loop |
| `src/s_movement.c`, `src/p_movement.c`, `src/r_movement.c` | The 11 operations |
| `libft/` | My libft |
