/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 16:59:20 by difortez          #+#    #+#             */
/*   Updated: 2026/10/04 13:09:53 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_ps *ps)
{
	int	min;
	int	p;

	while (ps->a != NULL)
	{
		min = find_min(ps->a, find_size(ps->a));
		p = find_place(ps->a, min);
		move_to_top(ps, 'a', p);
		pb(ps);
	}
	while (ps->b != NULL)
		pa(ps);
}
