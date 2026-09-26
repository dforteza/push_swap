/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 17:34:44 by difortez          #+#    #+#             */
/*   Updated: 2026/09/21 17:42:41 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Comprueba si a esta ordenada de menor a mayor.
 * @param a pila a revisar (puede estar vacia)
 * @return 1 si esta ordenada, 0 si no
 */
int	is_sorted(t_node *a)
{
	while (a && a->next)
	{
		if (a->index > a->next->index)
			return (0);
		a = a->next;
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
