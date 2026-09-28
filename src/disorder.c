/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 17:15:09 by difortez          #+#    #+#             */
/*   Updated: 2026/09/28 19:37:34 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Calcula el indice de desorden: pares mal ordenados entre pares totales.
 * @param a pila ya normalizada
 * @return de 0.0 (ordenada) a 1.0 (del reves)
 */
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
