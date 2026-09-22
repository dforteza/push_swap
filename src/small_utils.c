/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatrizdocarmo <beatrizdocarmo@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 20:43:48 by beatrizdoca       #+#    #+#             */
/*   Updated: 2026/09/20 23:53:14 by beatrizdoca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_last(t_node *stack)
{
	t_node	*last;

	if (stack == NULL || stack->next == NULL)
		return (stack);
	last = stack;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

int	find_max(t_node *stack)
{
	t_node	*current;
	int		max;

	current = stack;
	max = current->index;
	while (current != NULL)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	return (max);
}

int	find_min(t_node *stack)
{
	t_node	*current;
	int		min;

	current = stack;
	min = current->index;
	while (current != NULL)
	{
		if (current->index < min)
			min = current->index;
		current = current->next;
	}
	return (min);
}

int	find_place(t_node *stack, int n)
{
	t_node	*current;
	int		place;

	current = stack;
	place = 0;
	while (current != NULL)
	{
		if (current->index == n)
			return (place);
		current = current->next;
		place++;
	}
	return (place);
}

int	find_size(t_node *stack)
{
	t_node	*current;
	int		size;

	current = stack;
	size = 0;
	while (current != NULL)
	{
		current = current->next;
		size++;
	}
	return (size);
}