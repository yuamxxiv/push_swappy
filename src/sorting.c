/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 19:49:50 by amancheg          #+#    #+#             */
/*   Updated: 2026/03/28 23:25:00 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	pb(a, b);
	pb(a, b);
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
