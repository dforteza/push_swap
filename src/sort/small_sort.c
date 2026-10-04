/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 22:50:00 by beatrizdoca       #+#    #+#             */
/*   Updated: 2026/10/04 13:24:22 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Ordena los 3 nodos de a: sube el mayor al fondo y, si hace falta, sa.
 */
static void	sort_three(t_ps *ps)
{
	int	max;

	max = find_max(ps->a);
	if (ps->a->index == max)
		ra(ps);
	else if (ps->a->next->index == max)
		rra(ps);
	if (ps->a->index > ps->a->next->index)
		sa(ps);
}

/**
 * Ordena 4 nodos: pasa el menor a b, ordena los 3 de a y lo devuelve.
 */
static void	sort_four(t_ps *ps)
{
	int	min;
	int	p;

	min = find_min(ps->a, find_size(ps->a));
	p = find_place(ps->a, min);
	move_to_top(ps, 'a', p);
	pb(ps);
	sort_three(ps);
	pa(ps);
}

/**
 * Ordena 5 nodos: pasa los indices 0 y 1 a b, ordena los 3 de a y los
 * devuelve con el 1 primero.
 */
static void	sort_five(t_ps *ps)
{
	while (find_size(ps->a) > 3)
	{
		if (ps->a->index == 0 || ps->a->index == 1)
			pb(ps);
		else
			ra(ps);
	}
	sort_three(ps);
	if (ps->b->index < ps->b->next->index)
		sb(ps);
	pa(ps);
	pa(ps);
}

/**
 * Ordena a cuando tiene 5 nodos o menos, con el minimo de operaciones.
 */
void	small_sort(t_ps *ps)
{
	int	size;

	if (is_sorted(ps->a))
		return ;
	size = find_size(ps->a);
	if (size == 2)
		sa(ps);
	else if (size == 3)
		sort_three(ps);
	else if (size == 4)
		sort_four(ps);
	else if (size == 5)
		sort_five(ps);
}
