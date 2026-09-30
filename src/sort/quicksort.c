/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 14:45:45 by difortez          #+#    #+#             */
/*   Updated: 2026/09/30 20:14:30 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Ordena un tramo de 1 a 3 numeros que ya esta en la cima de a.
 * Solo usa sa, pb y pa para no mover lo que hay debajo.
 */
static void	sort_small_part(t_ps *ps, int size)
{
	if (size <= 1)
		return ;
	if (ps->a->value > ps->a->next->value)
		sa(ps);
	if (size == 3 && (ps->a->next->value > ps->a->next->next->value))
	{
		pb(ps);
		sa(ps);
		pa(ps);
		if (ps->a->value > ps->a->next->value)
			sa(ps);
	}
}

/**
 * Sube el tramo entero a la cima de a (solo se usa en el caso base).
 */
static void	part_to_top(t_ps *ps, t_part part)
{
	int	i;

	if (part.stack == 'a' && part.pos == BOTTOM)
	{
		i = -1;
		while (++i < part.size)
			rra(ps);
	}
	else if (part.stack == 'b' && part.pos == TOP)
	{
		i = -1;
		while (++i < part.size)
			pa(ps);
	}
	else if (part.stack == 'b' && part.pos == BOTTOM)
	{
		i = -1;
		while (++i < part.size)
		{
			rrb(ps);
			pa(ps);
		}
	}
}

/**
 * Reparte el tramo desde su zona: cada numero va a la zona de su grupo.
 * @param pivot limites: >= pivot[1] grande, >= pivot[0] mediano
 * @param dest  zonas de grandes, medianos y pequenos (set_dests)
 */
static void	partition(t_ps *ps, t_part part, int pivot[2], t_part dest[3])
{
	t_node	*top;
	int		i;

	i = 0;
	while (i < part.size)
	{
		bring_node_to_top(ps, part);
		if (part.stack == 'a')
			top = ps->a;
		else
			top = ps->b;
		if (top->index >= pivot[1])
			send_to_dest(ps, part, dest[0]);
		else if (top->index >= pivot[0])
			send_to_dest(ps, part, dest[1]);
		else
			send_to_dest(ps, part, dest[2]);
		i++;
	}
}

/**
 * Ordena un tramo y lo deja arriba de a: reparte en tres grupos por
 * tercios de indice y ordena grandes, medianos y pequenos en ese orden.
 */
static void	sort_part(t_ps *ps, t_part part)
{
	int		pivot[2];
	int		n;
	t_part	dest[3];
	t_node	*stack;
	
	if (part.stack == 'a')
		stack = ps->a;
	else
		stack = ps->b;
	if (part.pos == BOTTOM && part.size == find_size(stack))
		part.pos = TOP;
	if (part.size <= 3)
	{
		part_to_top(ps, part);
		sort_small_part(ps, part.size);
		return ;
	}
	n = part.size / 3;
	pivot[0] = find_min(part_start(ps, part), part.size) + n;
	pivot[1] = find_min(part_start(ps, part), part.size) + 2 * n;
	set_dests(part, n, dest);
	partition(ps, part, pivot, dest);
	sort_part(ps, dest[0]);
	sort_part(ps, dest[1]);
	sort_part(ps, dest[2]);
}

/**
 * Ordena a con quicksort de dos pivotes (--complex, O(n log n)).
 */
void	quick_sort(t_ps *ps)
{
	t_part	stack_a;

	stack_a = new_part('a', TOP, find_size(ps->a));
	sort_part(ps, stack_a);
}