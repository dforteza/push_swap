/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatrizdocarmo <beatrizdocarmo@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 22:50:00 by beatrizdoca       #+#    #+#             */
/*   Updated: 2026/09/22 17:25:40 by beatrizdoca      ###   ########.fr       */
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
	int		max;

	if (ps == NULL || ps->a == NULL)
		return ;
	if (ps->a->next == NULL || is_ready(ps->a) == 1)
		return ;
	max = find_max(ps->a);
	if (ps->a->index == max)
		ra(ps);
	else if (ps->a->next->index == max)
		rra(ps);
	if (ps->a->index > ps->a->next->index)
		sa(ps);
}

void	sort_four(t_ps *ps)
{
	int	min;

	if (ps == NULL || ps->a == NULL)
		return ;
	min = find_min(ps->a);
	while (ps->a->index != min)
	{
		if (find_place(ps->a, min) <= 2)
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
	//a veces queda más bonito reduciendo el número de variables
	t_node	*first;
	t_node	*second;

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
	first = ps->b;
	second = ps->b->next;
	if (first->index < second->index)
		sb(ps);
	pa(ps);
	pa(ps);
}

void	small_sort(t_ps *ps)
{
	t_node	*last;
	int		how_many;

	if (ps == NULL || ps->a == NULL)
		return ;
	if (ps->a->next == NULL || is_ready(ps->a) == 1)
		return ;
	last = find_last(ps->a);
	how_many = find_size(ps->a);
	if (how_many == 2)
		return (sa(ps));
	if (how_many == 3)
		return (sort_three(ps));
	if (how_many == 4)
		return (sort_four(ps));
	if (how_many == 5)
		return (sort_five(ps));
}