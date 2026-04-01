/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 19:49:50 by amancheg          #+#    #+#             */
/*   Updated: 2026/04/01 22:25:29 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_three(t_stack_node **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->nbr;
	second = (*stack)->next->nbr;
	third = (*stack)->next->next->nbr;
	if (first < second && second < third)
		return ;
	else if (first < second && first < third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first < second && second > third)
		rra(stack);
	else if (first > second && second < third)
		ra(stack);
	else
	{
		sa(stack);
		ra(stack);
	}
}

void	sort_many(t_stack_node **a, t_stack_node **b)
{
	pb(b, a);
	pb(b, a);
	while (stack_size(*a) > 3)
	{
		set_index(*a);
		set_index(*b);
		init_target_a(*a, *b);
		calculate_cost(*a, *b);
		find_cheapest(*a);
		move_cheapest(a, b);
	}
	sort_three(a);
	while (*b)
	{
		find_target(*a, *b);
		move_back(a, b);
	}
	bring_min_top(a);
}
