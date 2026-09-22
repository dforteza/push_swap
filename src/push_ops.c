/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatrizdocarmo <beatrizdocarmo@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 14:20:04 by beatrizdoca       #+#    #+#             */
/*   Updated: 2026/09/20 20:31:45 by beatrizdoca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Saca el primer nodo de src y lo coloca como primero de dst.
** Solo mueve: no imprime ni cuenta.
*/
void	push(t_node **src, t_node **dst)
{
	t_node	*target;

	if (src == NULL || *src == NULL || dst == NULL)
		return ;
	target = *src;
	*src = target->next;
	target->next = *dst;
	*dst = target;
}

/*
** pa mueve el primero de b a a, y pb al reves. Basta con un nodo en
** la pila de origen; si esta vacia no se hace ni se imprime nada.
*/
void	pa(t_ps *ps)
{
	if (ps == NULL || ps->b == NULL)
		return ;
	push(&(ps->b), &(ps->a));
	log_op(ps, "pa\n", PA);
}

void	pb(t_ps *ps)
{
	if (ps == NULL || ps->a == NULL)
		return ;
	push(&(ps->a), &(ps->b));
	log_op(ps, "pb\n", PB);
}
