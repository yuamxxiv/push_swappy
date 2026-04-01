/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 20:46:49 by amancheg          #+#    #+#             */
/*   Updated: 2026/04/01 22:27:54 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_max(t_stack_node *stack)
{
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max_node = stack;
	while (stack)
	{
		if (stack-> nbr > max_node->nbr)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}

//funzione helper per find target 
t_stack_node	*find_min(t_stack_node *stack)
{
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min_node = stack;
	while (stack)
	{
		if (stack->nbr < min_node->nbr)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

//funzione helper per find target  che trova il nodo con il valore minimo in a
t_stack_node	*get_min(t_stack_node *stack)
{
	t_stack_node	*current_node;
	t_stack_node	*min_node;

	current_node = stack;
	min_node = stack;
	while (current_node)
	{
		if (current_node->nbr < min_node->nbr)
			min_node = current_node;
		current_node = current_node->next;
	}
	return (min_node);
}
