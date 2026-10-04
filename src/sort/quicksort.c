/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 14:45:45 by difortez          #+#    #+#             */
/*   Updated: 2026/10/04 17:49:05 by difortez         ###   ########.fr       */
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

	i = 0;
	while (i < part.size)
	{
		if (part.stack == 'a' && part.pos == BOTTOM)
			rra(ps);
		else if (part.stack == 'b' && part.pos == TOP)
			pa(ps);
		else if (part.stack == 'b' && part.pos == BOTTOM)
		{
			rrb(ps);
			pa(ps);
		}
		i++;
	}
}

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

void	quick_sort(t_ps *ps)
{
	t_part	stack_a;

	stack_a = new_part('a', TOP, find_size(ps->a));
	sort_part(ps, stack_a);
}
