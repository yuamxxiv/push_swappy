/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 00:22:03 by amancheg          #+#    #+#             */
/*   Updated: 2026/03/27 17:06:52 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	parse_input(&stack_a, argv, argc);
	if (!is_sorted(stack_a))
	{
		if (stack_size(stack_a) == 2)
			sa(&stack_a);
		else if (stack_size(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_many(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

int	is_sorted(t_stack_node *stack)
{
	t_stack_node	*current_node;
	t_stack_node	*next_node;

	if (!stack || !stack->next)
		return (1);
	current_node = stack;
	while (current_node-> next)
	{
		next_node = current_node-> next;
		if (current_node->nbr > next_node->nbr)
			return (0);
		current_node = current_node -> next;
	}
	return (1);
}

int	stack_size(t_stack_node *stack)
{
	t_stack_node	*current_node;
	int				count;

	if (!stack)
		return (0);
	current_node = stack;
	count = 0;
	while (current_node)
	{
		count++;
		current_node = current_node->next;
	}
	return (count);
}
