/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatrizdocarmo <beatrizdocarmo@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 13:48:11 by beatrizdoca       #+#    #+#             */
/*   Updated: 2026/09/20 20:32:32 by beatrizdoca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
}

void	ra(t_ps *ps)
{
	if (ps == NULL || ps->a == NULL || ps->a->next == NULL)
		return ;
	rotate(&(ps->a));
	write(1, "ra\n", 3);
	ps->count[RA] = ps->count[RA] + 1;
}

void	rb(t_ps *ps)
{
	if (ps == NULL || ps->b == NULL || ps->b->next == NULL)
		return ;
	rotate(&(ps->b));
	write(1, "rb\n", 3);
	ps->count[RB] = ps->count[RB] + 1;
}

//hace falta revisar el caso de que un único stack pudiera hacerlo
void	rr(t_ps *ps)
{
	if (ps == NULL || ps->a == NULL || ps->a->next == NULL
		|| ps->b == NULL || ps->b->next == NULL)
		return ;
	rotate(&(ps->a));
	rotate(&(ps->b));
	write(1, "rr\n", 3);
	ps->count[RR] = ps->count[RR] + 1;
}
