/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 18:12:29 by difortez          #+#    #+#             */
/*   Updated: 2026/10/04 13:10:10 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	block_size(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

static void	push_blocks(t_ps *ps)
{
	int	size;
	int	lo;
	int	hi;

	size = block_size(find_size(ps->a));
	lo = 0;
	while (ps->a != NULL)
	{
		hi = lo + size;
		while (ps->a != NULL && lo < hi)
		{
			if (ps->a->index < hi)
			{
				pb(ps);
				lo++;
			}
			else
				ra(ps);
		}
	}
}

void	chunk_sort(t_ps *ps)
{
	int	max;
	int	p;

	push_blocks(ps);
	while (ps->b != NULL)
	{
		max = find_max(ps->b);
		p = find_place(ps->b, max);
		move_to_top(ps, 'b', p);
		pa(ps);
	}
}
