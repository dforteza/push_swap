/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 20:43:48 by beatrizdoca       #+#    #+#             */
/*   Updated: 2026/09/29 18:06:30 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Busca el mayor index de stack.
 * @param stack pila no vacia
 * @return el index mayor
 */
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

/**
 * Busca el menor index de stack.
 * @param stack pila no vacia
 * @return el index menor
 */
int	find_min(t_node *stack, int size)
{
	t_node	*current;
	int		min;
	int		i;

	current = stack;
	min = current->index;
	i = 0;
	while (i < size && current != NULL)
	{
		if (current->index < min)
			min = current->index;
		current = current->next;
		i++;
	}
	return (min);
}

/**
 * Busca en que posicion de stack esta el index n.
 * @return la posicion (0 = cima)
 */
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

/**
 * Cuenta los nodos de stack.
 * @return el numero de nodos
 */
int	find_size(t_node *stack)
{
	int		size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
