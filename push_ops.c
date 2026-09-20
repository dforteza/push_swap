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

void	pa(t_ps *ps)
{
	if (ps == NULL || ps->b == NULL)
		return ;
	push(&(ps->b), &(ps->a));
	write(1, "pa\n", 3);
	ps->count[PA] = ps->count[PA] + 1;
}

void	pb(t_ps *ps)
{
	if (ps == NULL || ps->a == NULL)
		return ;
	push(&(ps->a), &(ps->b));
	write(1, "pb\n", 3);
	ps->count[PB] = ps->count[PB] + 1;
}
