/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 20:43:48 by beatrizdoca       #+#    #+#             */
/*   Updated: 2026/09/26 13:34:27 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Busca el ultimo nodo de stack.
 * @return el ultimo nodo, o NULL si esta vacia
 */
t_node	*find_last(t_node *stack)
{
	t_node	*last;

	if (has_two(stack) == 0)
		return (stack);
	last = stack;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

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
