/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 17:34:44 by difortez          #+#    #+#             */
/*   Updated: 2026/09/28 19:23:17 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Comprueba si stack esta ordenada de menor stack mayor.
 * @param stack pila stack revisar (puede estar vacia)
 * @return 1 si esta ordenada, 0 si no
 */
int	is_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/**
 * Comprueba si stack tiene al menos dos nodos.
 * @return 1 si los tiene, 0 si no
 */
int	has_two(t_node *stack)
{
	if (stack == NULL || stack->next == NULL)
		return (0);
	return (1);
}
