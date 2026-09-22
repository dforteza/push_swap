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

void	reverse_rotate(t_node **stack)
{
	t_node	*first;
	t_node	*previous;
	t_node	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
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
	if (ps == NULL || ps->a == NULL || ps->a->next == NULL)
		return ;
	reverse_rotate(&(ps->a));
	write(1, "rra\n", 4);
	ps->count[RRA] = ps->count[RRA] + 1;
}

void	rrb(t_ps *ps)
{
	if (ps == NULL || ps->b == NULL || ps->b->next == NULL)
		return ;
	reverse_rotate(&(ps->b));
	write(1, "rrb\n", 4);
	ps->count[RRB] = ps->count[RRB] + 1;
}

//hace falta revisar el caso de que un único stack pudiera hacerlo
void	rrr(t_ps *ps)
{
	if (ps == NULL || ps->a == NULL || ps->a->next == NULL
		|| ps->b == NULL || ps->b->next == NULL)
		return ;
	reverse_rotate(&(ps->a));
	reverse_rotate(&(ps->b));
	write(1, "rrr\n", 4);
	ps->count[RRR] = ps->count[RRR] + 1;
}
