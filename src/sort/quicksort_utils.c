/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:11:54 by difortez          #+#    #+#             */
/*   Updated: 2026/09/30 19:58:14 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_part	new_part(char stack, int pos, int size)
{
	t_part	new;

	new.stack = stack;
	new.pos = pos;
	new.size = size;
	return (new);
}

t_node	*part_start(t_ps *ps, t_part part)
{
	t_node	*start;
	int		jumps;

	if (part.stack == 'a')
		start = ps->a;
	else
		start = ps->b;
	if (part.pos == BOTTOM)
	{
		jumps = find_size(start) - part.size;
		while (jumps > 0)
		{
			start = start->next;
			jumps--;
		}
	}
	return (start);
}

void	bring_node_to_top(t_ps *ps, t_part part)
{
	if (part.pos == BOTTOM)
	{
		if (part.stack == 'a')
			rra(ps);
		else
			rrb(ps);
	}
}

void	send_to_dest(t_ps *ps, t_part src, t_part dest)
{
	if (dest.stack != src.stack)
	{
		if (dest.stack == 'a')
			pa(ps);
		else
			pb(ps);
	}
	if (dest.pos == BOTTOM)
	{
		if (dest.stack == 'a')
			ra(ps);
		else
			rb(ps);
	}
}

void	set_dests(t_part src, int n, t_part dest[3])
{
	dest[0].stack = 'a';
	if (src.stack == 'a' && src.pos == TOP)
		dest[0].pos = BOTTOM;
	else
		dest[0].pos = TOP;
	dest[0].size = src.size - 2 * n;
	if (src.stack == 'a')
	{
		dest[1].stack = 'b';
		dest[1].pos = TOP;
	}
	else
	{
		dest[1].stack = 'a';
		dest[1].pos = BOTTOM;
	}
	dest[1].size = n;
	dest[2].stack = 'b';
	if (src.stack == 'b' && src.pos == BOTTOM)
		dest[2].pos = TOP;
	else
		dest[2].pos = BOTTOM;
	dest[2].size = n;
}
