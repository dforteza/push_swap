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

void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_ps *ps)
{
	if (ps == NULL || ps->a == NULL || ps->a->next == NULL)
		return ;
	swap(&(ps->a));
	write(1, "sa\n", 3);
	ps->count[SA] = ps->count[SA] + 1;
}

void	sb(t_ps *ps)
{
	if (ps == NULL || ps->b == NULL || ps->b->next == NULL)
		return ;
	swap(&(ps->b));
	write(1, "sb\n", 3);
	ps->count[SB] = ps->count[SB] + 1;
}

//hace falta revisar el caso de que un único stack pudiera hacerlo
void	ss(t_ps *ps)
{
	if (ps == NULL || ps->a == NULL || ps->a->next == NULL
		|| ps->b == NULL || ps->b->next == NULL)
		return ;
	swap(&(ps->a));
	swap(&(ps->b));
	write(1, "ss\n", 3);
	ps->count[SS] = ps->count[SS] + 1;
}
