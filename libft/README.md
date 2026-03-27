*This project has been created as part of the 42 curriculum by amancheg.*

# ft_libft

## Description
**Libft** is the first project at 42 School where you create your own C library from scratch. The goal is to recode essential functions from the standard C library (libc) and gain a deep understanding of how they work internally.

This project teaches fundamental programming concepts including:
- **Memory management** (malloc, free, pointers)
- **String manipulation** (copying, searching, modifying strings)
- **Linked lists** (creating and managing dynamic data structures)
- **File descriptors** (writing output to different streams)

### Functions

#### Character Checking Functions
- [`ft_isalpha`](./ft_isalpha.c) : Checks if a character is alphabetic (a-z, A-Z)
- [`ft_isdigit`](./ft_isdigit.c) : Checks if a character is a digit (0-9)
- [`ft_isalnum`](./ft_isalnum.c) : Checks if a character is alphanumeric (letter or digit)
- [`ft_isascii`](./ft_isascii.c) : Checks if a character is in the ASCII table (0-127)
- [`ft_isprint`](./ft_isprint.c) : Checks if a character is printable (space to ~)

#### String Functions
- [`ft_strlen`](./ft_strlen.c) : Calculates the length of a string
- [`ft_strlcpy`](./ft_strlcpy.c) : Copies a string with size limit (safer than strcpy)
- [`ft_strlcat`](./ft_strlcat.c) : Concatenates strings with size limit (safer than strcat)
- [`ft_strchr`](./ft_strchr.c) : Finds the first occurrence of a character in a string
- [`ft_strrchr`](./ft_strrchr.c) : Finds the last occurrence of a character in a string
- [`ft_strncmp`](./ft_strncmp.c) : Compares two strings up to n characters
- [`ft_strnstr`](./ft_strnstr.c) : Locates a substring within a string (with size limit)
- [`ft_strdup`](./ft_strdup.c) : Creates a duplicate copy of a string (allocates memory)
- [`ft_substr`](./ft_substr.c) : Extracts a substring from a string
- [`ft_strjoin`](./ft_strjoin.c) : Concatenates two strings into a new one
- [`ft_strtrim`](./ft_strtrim.c) : Removes specified characters from start and end of string
- [`ft_split`](./ft_split.c) : Splits a string into an array of words using a delimiter
- [`ft_strmapi`](./ft_strmapi.c) : Applies a function to each character of a string (creates new string)
- [`ft_striteri`](./ft_striteri.c) : Applies a function to each character of a string (modifies in place)

#### Memory Functions
- [`ft_memset`](./ft_memset.c) : Fills memory with a constant byte value.
- [`ft_bzero`](./ft_bzero.c) : Sets memory to zero (fills with '\0')
- [`ft_memcpy`](./ft_memcpy.c) : Copies memory from one location to another
- [`ft_memmove`](./ft_memmove.c) : Copies memory safely (handles overlapping areas)
- [`ft_memchr`](./ft_memchr.c) : Searches for a byte in memory
- [`ft_memcmp`](./ft_memcmp.c) : Compares two memory areas
- [`ft_calloc`](./ft_calloc.c) : Allocates memory and initializes it to zero

#### Conversion Functions
- [`ft_toupper`](./ft_toupper.c) : Converts a character to uppercase
- [`ft_tolower`](./ft_tolower.c) : Converts a character to lowercase
- [`ft_atoi`](./ft_atoi.c) : Converts a string to an integer
- [`ft_itoa`](./ft_itoa.c) : Converts an integer to a string

#### Output Functions
- [`ft_putchar_fd`](./ft_putchar_fd.c): Writes a character to a given file descriptor
- [`ft_putstr_fd`](./ft_putstr_fd.c): Writes a string to a given file descriptor
- [`ft_putendl_fd`](./ft_putendl_fd.c): Writes a string followed by newline to a file descriptor
- [`ft_putnbr_fd`](./ft_putnbr_fd.c): Writes an integer to a given file descriptor

#### Linked List Functions
- [`ft_lstnew`](./ft_lstnew.c): Creates a new list node
- [`ft_lstadd_front`](./ft_lstadd_front.c): Adds a node at the beginning of the list
- [`ft_lstadd_back`](./ft_lstadd_back.c): Adds a node at the end of the list
- [`ft_lstsize`](./ft_lstsize.c): Counts the number of nodes in a list
- [`ft_lstlast`](./ft_lstlast.c): Returns the last node of the list
- [`ft_lstdelone`](./ft_lstdelone.c): Deletes a single node and frees its memory
- [`ft_lstclear`](./ft_lstclear.c): Deletes and frees all nodes in the list
- [`ft_lstiter`](./ft_lstiter.c): Applies a function to each node of the list
- [`ft_lstmap`](./ft_lstmap.c): Creates a new list by applying a function to each node

## Instructions

Clone the repository.

### Compilation
To compile the library, run:
```bash
make
```

This will create the `libft.a` static library file.

### Available Commands
- `make` : Compiles the library
- `make clean` : Removes object files (.o)
- `make fclean` : Removes object files and the library (libft.a)
- `make re` : Recompiles everything from scratch

## Resources

Throughout this project, I utilized various learning resources to deepen my understanding:

- **Peer Learning**: Collaborating with fellow students and participating in peer evaluations helped me grasp difficult concepts through clear explanations and different perspectives.

- **Online Resources**: I supplemented my learning with YouTube tutorials and educational videos that provided visual explanations of complex topics.

- **AI Assistance**: I used AI tools as a learning companion, allowing me to ask questions repeatedly without hesitation until I fully understood challenging concepts. This provided a judgment-free environment to explore topics at my own pace.

These diverse resources complemented each other, helping me to finish the project.

