/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:52:06 by amancheg          #+#    #+#             */
/*   Updated: 2026/04/01 22:50:02 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>
# include <stddef.h>
# include "libft.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

t_stack_node	*stack_new(int value);
t_stack_node	*stack_last(t_stack_node *stack);
void			stack_add_back(t_stack_node **stack, t_stack_node *new_node);
int				main(int argc, char **argv);
int				is_sorted(t_stack_node *stack);
int				stack_size(t_stack_node *stack);
long long		ft_atol(const char *nptr, bool *error);
int				is_number(char *s);
int				is_duplicate(t_stack_node *stack_a, int n);
void			parse_input(t_stack_node **stack_a, char **argv, int argc);
void			free_error(t_stack_node **stack, char **args, bool ft_split);
void			free_split(char **args);
void			free_stack(t_stack_node **stack);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			set_index(t_stack_node *stack);
void			calculate_cost(t_stack_node *a, t_stack_node *b);
void			find_target(t_stack_node *a, t_stack_node *b);
t_stack_node	*get_min(t_stack_node *stack);
void			move_back(t_stack_node **a, t_stack_node **b);
void			bring_min_top(t_stack_node **a);
void			sort_three(t_stack_node **stack);
void			sort_many(t_stack_node **a, t_stack_node **b);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			finish_rotation(t_stack_node **stack,
					t_stack_node *top_node, char name);
void			find_cheapest(t_stack_node *stack);
void			move_cheapest(t_stack_node **a, t_stack_node **b);
t_stack_node	*find_min(t_stack_node *stack);
void			init_target_a(t_stack_node *a, t_stack_node *b);
t_stack_node	*find_max(t_stack_node *stack);
#endif
