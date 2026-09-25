/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatrizdocarmo <beatrizdocarmo@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 22:50:00 by beatrizdoca       #+#    #+#             */
/*   Updated: 2026/09/24 23:42:52 by beatrizdoca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ready(t_node *stack)
{
	t_node	*current;

	if (stack == NULL || stack->next == NULL)
		return (1);
	current = stack;
	while (current->next != NULL)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_three(t_ps *ps)
{
	int	max;

	max = find_max(ps->a);
	if (ps == NULL || ps->a == NULL)
		return ;
	if (ps->a->next == NULL || is_ready(ps->a) == 1)
		return ;
	if (ps->a->index == max)
		ra(ps);
	else if (ps->a->next->index == max)
		rra(ps);
	if (ps->a->index > ps->a->next->index)
		sa(ps);
}

void	sort_four(t_ps *ps)
{
	if (ps == NULL || ps->a == NULL)
		return ;
	while (ps->a->index != 0)
	{
		if (find_where(ps->a, 0) <= 2)
			ra(ps);
		else
			rra(ps);
	}
	pb(ps);
	sort_three(ps);
	pa(ps);
}

void	sort_five(t_ps *ps)
{
	if (ps == NULL || ps->a == NULL)
		return ;
	while (find_size(ps->a) > 3)
	{
		if (ps->a->index == 0 || ps->a->index == 1)
			pb(ps);
		else
			ra(ps);
	}
	sort_three(ps);
	if (ps->b->index < ps->b->next->index)
		sb(ps);
	pa(ps);
	pa(ps);
}

void	small_sort(t_ps *ps)
{
	int	how_many;

	if (ps == NULL || ps->a == NULL)
		return ;
	if (ps->a->next == NULL || is_ready(ps->a) == 1)
		return ;
	how_many = find_size(ps->a);
	if (how_many == 2)
		sa(ps);
	else if (how_many == 3)
		sort_three(ps);
	else if (how_many == 4)
		sort_four(ps);
	else if (how_many == 5)
		sort_five(ps);
}
