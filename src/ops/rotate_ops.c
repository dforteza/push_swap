/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 13:48:11 by beatrizdoca       #+#    #+#             */
/*   Updated: 2026/09/22 16:00:11 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sube todos los nodos una posicion: el primero pasa a ser el ultimo.
** Solo mueve: no imprime ni cuenta.
*/
void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (stack == NULL || has_two(*stack) == 0)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
}

/*
** ra, rb y rr aplican rotate a la pila que toca y registran la
** operacion. Misma regla que en swap: si ninguna pila implicada
** llega a dos nodos, no se hace ni se imprime nada.
*/
void	ra(t_ps *ps)
{
	if (ps == NULL || has_two(ps->a) == 0)
		return ;
	rotate(&(ps->a));
	log_op(ps, "ra\n", RA);
}

void	rb(t_ps *ps)
{
	if (ps == NULL || has_two(ps->b) == 0)
		return ;
	rotate(&(ps->b));
	log_op(ps, "rb\n", RB);
}

void	rr(t_ps *ps)
{
	if (ps == NULL || (has_two(ps->a) == 0 && has_two(ps->b) == 0))
		return ;
	rotate(&(ps->a));
	rotate(&(ps->b));
	log_op(ps, "rr\n", RR);
}
