/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 17:15:11 by difortez          #+#    #+#             */
/*   Updated: 2026/10/04 11:55:42 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (tmp_i->value > tmp_j->value)
				c++;
			tmp_j = tmp_j->next;
		}
		tmp_i->index = c;
		tmp_i = tmp_i->next;
	}
}

double	calculate_disorder(t_node *a)
{
	t_node	*tmp_i;
	t_node	*tmp_j;
	int		mistakes;
	int		total;

	mistakes = 0;
	total = 0;
	tmp_i = a;
	while (tmp_i)
	{
		tmp_j = tmp_i->next;
		while (tmp_j)
		{
			total++;
			if (tmp_i->index > tmp_j->index)
				mistakes++;
			tmp_j = tmp_j->next;
		}
		tmp_i = tmp_i->next;
	}
	if (total == 0)
		return (0.0);
	return ((double)mistakes / (double)total);
}
