/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestione_lista.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:13:19 by amancheg          #+#    #+#             */
/*   Updated: 2026/04/01 19:30:38 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//crea un nuovo nodo con il valore intero passato 
t_stack_node	*stack_new(int value)
{
	t_stack_node	*new_nodo;

	new_nodo = NULL;
	new_nodo = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_nodo)
		return (NULL);
	new_nodo -> nbr = value;
	new_nodo -> index = 0;
	new_nodo -> push_cost = 0;
	new_nodo -> above_median = false;
	new_nodo -> cheapest = false;
	new_nodo -> target_node = NULL;
	new_nodo -> next = NULL;
	new_nodo -> prev = NULL;
	return (new_nodo);
}

//trova l'ultimo nodo dello stack
t_stack_node	*stack_last(t_stack_node *stack)
{
	t_stack_node	*current_node;

	if (!stack)
		return (NULL);
	current_node = stack;
	while (current_node->next)
		current_node = current_node->next;
	return (current_node);
}

//aggiunge un nodo in fondo / alla fine  dello stack
void	stack_add_back(t_stack_node **stack, t_stack_node *new_node)
{
	t_stack_node	*last_node;

	if (!stack || !new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last_node = stack_last(*stack);
	last_node->next = new_node;
	new_node->prev = last_node;
	new_node->next = NULL;
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
