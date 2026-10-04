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

static void	push(t_node **src, t_node **dst)
{
	t_node	*target;

	target = *src;
	*src = target->next;
	target->next = *dst;
	*dst = target;
}

void	pa(t_ps *ps)
{
	if (ps->b == NULL)
		return ;
	push(&(ps->b), &(ps->a));
	log_op(ps, "pa\n", PA);
}

void	pb(t_ps *ps)
{
	if (ps->a == NULL)
		return ;
	push(&(ps->a), &(ps->b));
	log_op(ps, "pb\n", PB);
}
