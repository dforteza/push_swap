/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 14:45:45 by difortez          #+#    #+#             */
/*   Updated: 2026/09/29 19:23:23 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	partition(t_ps *ps, int size, int pivot[2])
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ps->a->index >= pivot[1])
			ra(ps);
		else if (ps->a->index >= pivot[0])
			pb(ps);
		else
		{
			pb(ps);
			rb(ps);
		}
		i++;
	}
}

t_part	new_part(char stack, int pos, int size)
{
	t_part	new;

	new.stack = stack;
	new.pos = pos;
	new.size = size;
	return (new);
}

static void	sort_part(t_ps *ps, t_part part)
{
	int	pivot[2];
	int	min;
	int	n;

	// 1. Traer el tramo arriba de A
	part_to_top(ps, part);
	// 2. Si size ≤ 3: caso base y return
	if (part.size <= 3)
	{
		sort_small_part(ps, part.size);
		return ;
	}
	// 3. Calcular los pivotes
	min = find_min(ps->a, part.size);
	n = part.size / 3;
	pivot[0] = min + n;
	pivot[1] = min + 2 * n;
	// 4. Pasada (repartir en tres grupos)
	partition(ps, part.size, pivot);
	// 5. Recursión (grandes, medianos, pequeños)
	sort_part(ps, new_part('a', BOTTOM, part.size - 2 * n));
	sort_part(ps, new_part('b', TOP, n));
	sort_part(ps, new_part('b', BOTTOM, n));
}

void	quick_sort(t_ps *ps)
{
	t_part	stack_a;

	stack_a = new_part('a', TOP, find_size(ps->a));
	sort_part(ps, stack_a);
}
