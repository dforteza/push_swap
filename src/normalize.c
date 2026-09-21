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

/*
** Sustituye cada valor por su posicion en la lista ordenada: el nodo mas
** pequeno recibe el indice 0 y el mayor n-1. El indice de un nodo es
** cuantos valores hay menores que el, asi que por cada nodo recorre la
** pila entera contando. No mueve ningun nodo, solo rellena el campo
** index. Es O(n^2), pero solo se ejecuta una vez y no cuenta como
** operacion de ordenacion.
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
