/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatrizdocarmo <beatrizdocarmo@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 13:29:01 by beatrizdoca       #+#    #+#             */
/*   Updated: 2026/09/28 19:11:12 by beatrizdoca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//si meterla en sort_utils
int	last_index(t_node *stack)
{
	t_node	*last;

	last = find_last(stack);
	return (last->index);
}

int	find_order(t_node *stack, int n)
{
	t_node	*current;
	int		where_to;

	if (n > find_max(stack) || n < find_min(stack))
		return (find_max(stack));
	current = stack;
	where_to = -1;
	while (current != NULL)
	{
		if (current->index < n && current->index > where_to)
			where_to = current->index;
		current = current->next;
	}
	return (where_to);
}

void	order_chaos(t_ps *ps)
{
	int	where_to;

	if (ps == NULL || ps->a == NULL)
		return ;
	if (find_size(ps->b) < 2)
	{
		pb(ps);
		if (find_size(ps->b) == 2 && ps->b->index < ps->b->next->index)
			sb(ps);
	}
	else
	{
		where_to = find_order(ps->b, ps->a->index);
		move_to_top(ps, 'b', find_place(ps->b, where_to));
		pb(ps);
	}
}

void	push_chaos(t_ps *ps)
{
	int	current_max;
	int	size;
	int	i;

	if (ps == NULL || ps->a == NULL)
		return ;
	size = find_size(ps->a);
	i = 0;
	current_max = -1;
	while (i < size)
	{
		if (ps->a->index < current_max)
			order_chaos(ps);
		else
		{
			current_max = ps->a->index;
			ra(ps);
		}
		i++;
	}
}

//first y last están ahí por entender más rápido al leer
//que también pueden no estar
void	sort_little_chaos(t_ps *ps)
{
	int	first;
	int	last;

	if (ps == NULL || has_two(ps->a) == 0)
		return ;
	move_to_top(ps, 'a', find_place(ps->a, 0));
	push_chaos(ps);
	if (ps->b == NULL)
	{
		move_to_top(ps, 'a', find_place(ps->a, 0));
		return ;
	}
	move_to_top(ps, 'b', find_place(ps->b, find_max(ps->b)));
	while (ps->b != NULL)
	{
		first = ps->a->index;
		last = last_index(ps->a);
		if ((ps->b->index > last && ps->b->index < first)
			|| (ps->b->index > last && last > first)
			|| (ps->b->index < first && last > first))
			pa(ps);
		else
			rra(ps);
	}
	move_to_top(ps, 'a', find_place(ps->a, 0));
}
