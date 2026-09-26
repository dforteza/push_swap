/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_chaos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatrizdocarmo <beatrizdocarmo@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 22:38:28 by beatrizdoca       #+#    #+#             */
/*   Updated: 2026/09/25 17:23:15 by beatrizdoca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//eso va a recaer en más que O(n)
//no lo tengo muy bien claro para el bajo índice
//pero es que no es una LIS, la LIS tiene una otra lógica
//es lo que yo había entendido como LIS
//es básicamente un insertion pero con un pequeño cálculo de coste
//que también poderia ser mejor
//estoy viendo de como hacer la LIS bien
//o hacer que eso sea un merge incorporando orden del otro lado
//por si tiene sentido

int	find_last(t_node *stack)
{
	t_node	*current;

	current = stack;
	while (current->next != NULL)
		current = current->next;
	return (current->index);
}

int	find_distance(t_node *stack, int n)
{
	t_node	*current;
	int		position;

	current = stack;
	position = 0;
	if (n <= 0)
		return (find_where(stack, 0));
	while (current != NULL)
	{
		if (current->index > n)
			return (position);
		current = current->next;
		position++;
	}
	return (find_where(stack, find_min(stack)));
}

//pendiente de revisar
void	push_chaos(t_ps *ps)
{
	int	current_max;
	int	size;
	int	i;

	if (ps == NULL || ps->a == NULL)
		return ;
	current_max = -1;
	size = find_size(ps->a);
	i = 0;
	while (i < size)
	{
		if (ps->a->index < current_max)
		{
			pb(ps);
			if (ps->b->index < (size / 2))
				rb(ps);
		}
		else
		{
			current_max = ps->a->index;
			ra(ps);
		}
		i++;
	}
}

//pendiente de revisar
void	find_order(t_ps *ps)
{
	int	distance;
	int	size;

	if (ps == NULL || ps->a == NULL)
		return ;
	if (ps->b == NULL)
		distance = find_distance(ps->a, -1);
	else
		distance = find_distance(ps->a, ps->b->index);
	size = find_size(ps->a);
	if (distance > (size / 2))
	{
		distance = size - distance;
		while (distance > 0)
		{
			rra(ps);
			distance--;
		}
	}
	else
	{
		while (distance > 0)
		{
			ra(ps);
			distance--;
		}
	}
}

void	sort_little_chaos(t_ps *ps)
{
	if (ps == NULL || has_two(ps->a) == 0)
		return ;
	push_chaos(ps);
	while (ps->b != NULL)
	{
		find_order(ps);
		pa(ps);
	}
	find_order(ps);
}
