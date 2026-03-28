NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iincludes -Ilibft -g

# Percorsi per la Libft
LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

# Sorgenti di push_swap
SRCS        = src/main.c src/parse_input.c src/parsing.c src/cheap.c src/gestione_lista.c src/push.c src/reverse_rotate.c src/rotate.c src/sort_many.c src/sorting.c src/swap.c
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Questa regola compila la libft chiamando il suo Makefile interno
$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all 

.PHONY: all clean fclean re
