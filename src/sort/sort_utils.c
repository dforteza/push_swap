/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 13:55:00 by difortez          #+#    #+#             */
/*   Updated: 2026/09/26 13:55:00 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Hace times veces ra (si name es 'a') o rb.
 */
static void	rotate_up(t_ps *ps, char name, int times)
{
	while (times > 0)
	{
		if (name == 'a')
			ra(ps);
		else
			rb(ps);
		times--;
	}
}

/**
 * Hace times veces rra (si name es 'a') o rrb.
 */
static void	rotate_down(t_ps *ps, char name, int times)
{
	while (times > 0)
	{
		if (name == 'a')
			rra(ps);
		else
			rrb(ps);
		times--;
	}
}

/**
 * Sube el nodo de la posicion p a la cima de name por el camino corto.
 * @param name pila donde trabajar: 'a' o 'b'
 * @param p    posicion del nodo (0 = cima)
 */
void	move_to_top(t_ps *ps, char name, int p)
{
	int	n;

	if (name == 'a')
		n = find_size(ps->a);
	else
		n = find_size(ps->b);
	if (p <= n / 2)
		rotate_up(ps, name, p);
	else
		rotate_down(ps, name, n - p);
}
