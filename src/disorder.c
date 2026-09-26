/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 17:15:09 by difortez          #+#    #+#             */
/*   Updated: 2026/09/21 17:55:57 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Calcula el indice de desorden: pares mal ordenados entre pares totales.
 * @param a pila ya normalizada
 * @return de 0.0 (ordenada) a 1.0 (del reves)
 */
double	compute_disorder(t_node *a)
{
	t_node	*i;
	t_node	*j;
	int		mistakes;
	int		total;

	mistakes = 0;
	total = 0;
	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total++;
			if (i->index > j->index)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total == 0)
		return (0.0);
	return ((double)mistakes / (double)total);
}
