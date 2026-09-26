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

/**
 * Pasa la cima de src a la cima de dst. Solo mueve: no imprime.
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

/**
 * pa pasa la cima de b a a; pb, la de a a b.
 * Si la pila de origen esta vacia, no hacen nada.
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
