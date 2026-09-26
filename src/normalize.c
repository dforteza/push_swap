/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 17:15:11 by difortez          #+#    #+#             */
/*   Updated: 2026/09/21 17:24:05 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Pone en cada index su posicion final: cuantos valores hay menores.
 */
void	normalize(t_ps *ps)
{
	t_node	*i;
	t_node	*j;
	int		c;

	if (!ps)
		return ;
	i = ps->a;
	while (i)
	{
		c = 0;
		j = ps->a;
		while (j)
		{
			if (j->value < i->value)
				c++;
			j = j->next;
		}
		i->index = c;
		i = i->next;
	}
}
