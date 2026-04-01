/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 19:35:14 by amancheg          #+#    #+#             */
/*   Updated: 2026/04/01 22:51:40 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ora b e quasi finito quindi dobbiamo reinserire 
//ogni nodo di b nel posto giusto in a 
void	find_target(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target;

	while (b)
	{
		target = NULL;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr)
			{
				if (!target || current_a->nbr < target->nbr)
					target = current_a;
			}
			current_a = current_a->next;
		}
		if (!target)
			b->target_node = find_min(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	move_back(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*target;

	target = (*b)->target_node;
	while (*a != target)
	{
		if (target->above_median)
			ra(a);
		else
			rra(a);
	}
	pa(a, b);
}

void	bring_min_top(t_stack_node **a)
{
	t_stack_node	*min;

	set_index(*a);
	min = get_min(*a);
	while (*a != min)
	{
		if (min->above_median)
			ra(a);
		else
			rra(a);
	}
}
