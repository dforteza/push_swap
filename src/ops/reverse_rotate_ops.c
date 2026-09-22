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

/*
** Baja todos los nodos una posicion: el ultimo pasa a ser el primero.
** Solo mueve: no imprime ni cuenta.
*/
void	reverse_rotate(t_node **stack)
{
	t_node	*first;
	t_node	*previous;
	t_node	*last;

	if (stack == NULL || has_two(*stack) == 0)
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

/*
** rra, rrb y rrr aplican reverse_rotate a la pila que toca y
** registran la operacion. Misma regla que en swap y rotate.
*/
void	rra(t_ps *ps)
{
	if (ps == NULL || has_two(ps->a) == 0)
		return ;
	reverse_rotate(&(ps->a));
	log_op(ps, "rra\n", RRA);
}

void	rrb(t_ps *ps)
{
	if (ps == NULL || has_two(ps->b) == 0)
		return ;
	reverse_rotate(&(ps->b));
	log_op(ps, "rrb\n", RRB);
}

void	rrr(t_ps *ps)
{
	if (ps == NULL || (has_two(ps->a) == 0 && has_two(ps->b) == 0))
		return ;
	reverse_rotate(&(ps->a));
	reverse_rotate(&(ps->b));
	log_op(ps, "rrr\n", RRR);
}
