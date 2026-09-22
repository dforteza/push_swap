/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 16:59:20 by difortez          #+#    #+#             */
/*   Updated: 2026/09/22 17:26:16 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Ordena la pila a por seleccion (estrategia --simple, decision 12).
** El mapa es este:
**   1. mientras queden nodos en a:
**   2.      m = indice mas pequeno que queda en a   (find_min)
**   3.      p = en que posicion esta                (find_place)
**   4.      subirlo arriba por el camino mas corto  (ra o rra)
**   5.      pb
**   6. vaciar b de vuelta a a con pa
** Como se empuja siempre el minimo, b queda ordenada al reves y el
** paso 6 deja a ordenada sin comparar nada mas.
*/

/*
** Sube a lo alto de a el nodo que esta en la posicion p, eligiendo el
** camino mas corto: p rotaciones hacia arriba o n - p hacia abajo
** (decision 18). Cuando llegue chunks, esta funcion se comparte.
*/
static void	move_to_top(t_ps *ps, int p, int n)
{
	if (p <= n / 2)
	{
		while (p-- > 0)
			ra(ps);
	}
	else
	{
		while (p++ < n)
			rra(ps);
	}
}

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
		move_to_top(ps, p, find_size(ps->a));
		pb(ps);
	}
	while (ps->b != NULL)
		pa(ps);
}
