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

/*
** Devuelve 1 si la pila esta ordenada de menor a mayor por index.
** Una pila vacia o de un solo nodo cuenta como ordenada.
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

/*
** Devuelve 1 si la pila tiene al menos dos nodos, que es lo minimo
** para que swap, rotate y reverse_rotate cambien algo.
*/
int	has_two(t_node *stack)
{
	if (stack == NULL || stack->next == NULL)
		return (0);
	return (1);
}
