/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatrizdocarmo <beatrizdocarmo@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 14:09:14 by beatrizdoca       #+#    #+#             */
/*   Updated: 2026/09/20 20:32:06 by beatrizdoca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_node **stack)
{
	t_node	*first;
	t_node	*previous;
	t_node	*last;

	first = *stack;
	last = *stack;
	while (last->next != NULL)
	{
		previous = last;
		last = last->next;
	}
	previous->next = NULL;
	last->next = first;
	*stack = last;
}

void	rra(t_ps *ps)
{
	if (has_two(ps->a) == 0)
		return ;
	reverse_rotate(&(ps->a));
	log_op(ps, "rra\n", RRA);
}

void	rrb(t_ps *ps)
{
	if (has_two(ps->b) == 0)
		return ;
	reverse_rotate(&(ps->b));
	log_op(ps, "rrb\n", RRB);
}

void	rrr(t_ps *ps)
{
	if (has_two(ps->a) == 0 && has_two(ps->b) == 0)
		return ;
	reverse_rotate(&(ps->a));
	reverse_rotate(&(ps->b));
	log_op(ps, "rrr\n", RRR);
}
