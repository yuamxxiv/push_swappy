/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 21:10:40 by amancheg          #+#    #+#             */
/*   Updated: 2026/03/27 17:16:09 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//controlla se una stringa contiene solo numeri || segni + -

int	is_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}
//scorre lo stack per vedere se il numero che si sta inserendo esiste gia'

int	is_duplicate(t_stack_node *stack_a, int n)
{
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		if (stack_a -> nbr == n)
			return (1);
		stack_a = stack_a -> next;
	}
	return (0);
}
//funzione che prende argv e fa il check con le funzioni sopra e riempe 
//lo stack_a

void	free_error(t_stack_node **stack, char **args, bool ft_split)
{
	free_stack(stack);
	if (ft_split && args)
		free_split(args);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_split(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current -> next;
		free (current);
		current = tmp;
	}
	*stack = NULL;
}
