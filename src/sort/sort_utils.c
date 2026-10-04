/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 13:55:00 by difortez          #+#    #+#             */
/*   Updated: 2026/10/04 12:24:08 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
