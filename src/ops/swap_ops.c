/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatrizdocarmo <beatrizdocarmo@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 13:05:40 by beatrizdoca       #+#    #+#             */
/*   Updated: 2026/09/20 20:32:41 by beatrizdoca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Intercambia los dos primeros nodos. Solo mueve: no imprime ni comprueba.
 */
void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

/**
 * sa, sb y ss: swap en a, en b o en ambas, e imprimen la operacion.
 * Si no hay dos nodos, no hacen nada (no gastan operacion).
 */
void	sa(t_ps *ps)
{
	if (has_two(ps->a) == 0)
		return ;
	swap(&(ps->a));
	log_op(ps, "sa\n", SA);
}

void	sb(t_ps *ps)
{
	if (has_two(ps->b) == 0)
		return ;
	swap(&(ps->b));
	log_op(ps, "sb\n", SB);
}

void	ss(t_ps *ps)
{
	if (has_two(ps->a) == 0 && has_two(ps->b) == 0)
		return ;
	swap(&(ps->a));
	swap(&(ps->b));
	log_op(ps, "ss\n", SS);
}
