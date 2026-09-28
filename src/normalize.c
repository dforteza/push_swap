/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 17:15:11 by difortez          #+#    #+#             */
/*   Updated: 2026/09/28 19:36:50 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Pone en cada index su posicion final: cuantos valores hay menores.
 */
void	normalize(t_node *a)
{
	t_node	*tmp_i;
	t_node	*tmp_j;
	int		c;

	tmp_i = a;
	while (tmp_i)
	{
		c = 0;
		tmp_j = a;
		while (tmp_j)
		{
			if (tmp_j->value < tmp_i->value)
				c++;
			tmp_j = tmp_j->next;
		}
		tmp_i->index = c;
		tmp_i = tmp_i->next;
	}
}
