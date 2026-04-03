*This project was created as part of the 42 curriculum by **amancheg**.*

## Description

**push_swap** is a C project that challenges you to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. It requires a deep understanding of complexity and algorithm optimization.

### The Goal

You are given two stacks, **A** and **B**:

- **Stack A**: Initialized with a series of random, non-duplicated integers (positive or negative).
- **Stack B**: Starts empty.
- **Objective**: Sort all numbers into Stack A in ascending order using the minimum number of movements.

### The Movements

To manipulate the stacks, you must use these 11 authorized operations:

| Category | Command | Description |
| :--- | :--- | :--- |
| **Swap** | `sa`, `sb`, `ss` | Swap the first 2 elements at the top of the stack. |
| **Push** | `pa`, `pb` | Take the top element of one stack and put it on the other. |
| **Rotate** | `ra`, `rb`, `rr` | Shift up all elements by 1. The first element becomes the last. |
| **Rev Rotate** | `rra`, `rrb`, `rrr` | Shift down all elements by 1. The last element becomes the first. |

### The Algorithm: Greedy (The Turk)

I implemented a **Greedy Algorithm** (often referred to as the "Turk" approach). It works by:

1. Calculating the cost (number of moves) for every possible element to reach its target position.
2. Selecting the **"Cheapest"** node (the one requiring the fewest total operations).
3. Using double rotations (`rr`, `rrr`) whenever possible to maximize efficiency.

---

## The Function Map

### Core Program Logic

- **`main`**: The entry point of the program. It handles the initial setup, validates the number of arguments, calls the parsing functions, and determines which sorting algorithm to execute (e.g., `sort_three` or the `greedy` algorithm) based on the stack size.

### Input Parsing & Validation

- **`parse_input`**: The primary "manager" for input. It checks if numbers are passed as multiple arguments or as a single quoted string. If it's a string, it uses `ft_split` to break it down. It then converts strings to integers and populates Stack A.
- **`ft_atol`**: (ASCII to Long) Converts a string into a number. It uses a `long` type to detect **integer overflow** (numbers outside the range of `-2147483648` to `2147483647`) before saving them into the stack.
- **`is_number`**: Scans a string character by character. It returns `true` only if the string contains digits (0-9) and an optional `+` or `-` sign at the very beginning. If it encounters letters or symbols, it triggers an error.
- **`is_duplicate`**: Iterates through Stack A to verify that the number being added isn't already present. Since the project forbids duplicates, this ensures data integrity.

### Stack Management (Linked List Utils)

- **`stack_new`**: Allocates memory for a new node and initializes its value (`nbr`) and pointers (`next`, `prev`).
- **`stack_last`**: Traverses the list from the top to return a pointer to the very last node.
- **`stack_add_back`**: Takes a newly created node and attaches it to the end of the existing linked list.
- **`stack_size`**: Counts the total number of nodes in the stack. This is essential for calculating the **median** and determining rotation directions.

### The Turk Algorithm Logic

#### Phase 1: Moving A to B

- **`set_index`**: Assigns each node its current position in the stack and marks whether it is **above or below the median**.
- **`init_target_a`**: For every node in A, it finds the "Target" position in B. It looks for the largest number in B that is still smaller than the current node in A.
- **`calculate_cost`**: Math logic that determines how many moves are needed to bring a node in A and its target in B to the top. It prioritizes nodes where both can be moved using double rotations (`rr` or `rrr`) to save moves.

#### Phase 2: Moving B to A

- **`init_target_b`**: Finds the correct spot in A to return the numbers from B. It looks for the smallest number in A that is larger than the current node in B.
- **`move_back`**: Executes the operations to push nodes back into A while maintaining the correct order.
- **`min_to_top`**: Once all numbers are back in A, this performs the final rotations to ensure the smallest number is at the top of the stack.

#### General Utils

- **`find_max` / `find_min`**: Helper functions to locate the highest or lowest values in a stack. These are used to reset targets when a number is the smallest or largest in the entire set.

### Efficiency & Cheapest Logic

- **`find_cheapest`**: Scans the costs calculated for every node in A and flags the one that requires the fewest total operations to move.
- **`move_cheapest`**: Orchestrates the actual movement. It uses double rotations as much as possible for the "cheapest" node and its target, then finishes with single rotations.
- **`finish_rotation`**: If one stack is ready but the other still needs to move, this function completes the remaining single rotations.

### Cleanup & Error Handling

- **`free_error`**: The "panic button." It prints `Error` to the standard error output, frees all allocated memory, and exits the program cleanly.
- **`free_split`**: Specifically frees the memory allocated by `ft_split`, ensuring both the individual strings and the pointer array are cleared.
- **`free_stack`**: Iterates through the linked list and frees every node to prevent memory leaks.

### Performance Summary

- **`is_sorted`**: A simple check to see if Stack A is already in order. If it is, the program terminates immediately.
- **`sort_three`**: A hard-coded logic for 3 numbers that ensures they are sorted in **2 moves or fewer**.
- **`sort_many`**: The main Greedy loop that handles 100, 500, or more numbers by repeatedly finding and moving the cheapest node.

---

## Instructions

Clone the repository.

### Compilation

To compile the project and generate the executable, run:

```bash
make
```

This will create the `push_swap` executable file.

### Available Commands

- `make` : Compiles the source files and generates the push_swap executable.
- `make clean` : Removes object files (.o)
- `make fclean` : Removes the object files and the push_swap executable.
- `make re` : Forces recompilation of the entire project.

### Usage

Run the program by passing a list of integers as arguments.

```bash
./push_swap 3 0 9 2 -1
```

**3 numbers**
```bash
ARG="2 1 0"; ./push_swap $ARG | ./checker_linux $ARG
```

**5 numbers**
```bash
ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_linux $ARG
```

**100 numbers**
```bash
ARG=$(python3 -c "import random; print(*(random.sample(range(-2000, 2000), 100)))"); ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l
```

**500 numbers**
```bash
ARG=$(python3 -c "import random; print(*(random.sample(range(-2000, 2000), 500)))"); ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l
```

**Valgrind**
```bash
ARG="3 0 9 2 -1"; valgrind --leak-check=full ./push_swap $ARG
```

**Empty String**
```bash
./push_swap ""
```

**No Numbers**
```bash
./push_swap 1 2 a 4
```

---

## Resources

Throughout this project, I utilized various learning resources to deepen my understanding:

- **Peer Learning**: Collaborating with fellow students and participating in peer evaluations helped me grasp difficult concepts through clear explanations and different perspectives.

- **Online Resources**: I supplemented my learning with YouTube tutorials and educational videos that provided visual explanations of complex topics.

- **AI Assistance**: I used AI tools as a learning companion, allowing me to ask questions repeatedly without hesitation until I fully understood challenging concepts. This provided a judgment-free environment to explore topics at my own pace.

These diverse resources complemented each other, helping me to finish the project.
