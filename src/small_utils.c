/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatrizdocarmo <beatrizdocarmo@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 20:43:48 by beatrizdoca       #+#    #+#             */
/*   Updated: 2026/09/25 01:39:21 by beatrizdoca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_where(t_node *stack, int n)
{
	t_node	*current;
	int		position;

	current = stack;
	position = 0;
	while (current != NULL)
	{
		if (current->index == n)
			return (position);
		current = current->next;
		position++;
	}
	return (position);
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
