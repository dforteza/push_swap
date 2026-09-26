/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 16:59:20 by difortez          #+#    #+#             */
/*   Updated: 2026/09/26 13:46:40 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Ordena a por seleccion (--simple, O(n^2)).
 * Pasa a b siempre el minimo de a y al final lo devuelve todo con pa.
 */
void	selection_sort(t_ps *ps)
{
	int	m;
	int	p;

	if (ps == NULL)
		return ;
	while (ps->a != NULL)
	{
		m = find_min(ps->a);
		p = find_place(ps->a, m);
		move_to_top(ps, 'a', p);
		pb(ps);
	}
	while (ps->b != NULL)
		pa(ps);
}
