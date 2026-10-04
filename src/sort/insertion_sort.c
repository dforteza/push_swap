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

/**
 * Devuelve el index del ultimo nodo de stack (pila no vacia).
 */
static int	last_index(t_node *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack->index);
}

/**
 * Busca el index de b que debe quedar justo debajo de n para que b siga
 * ordenada de mayor a menor.
 * @return el mayor index menor que n, o el maximo de b si n es nuevo
 *         maximo o nuevo minimo
 */
static int	find_order(t_node *stack, int n)
{
	t_node	*current;
	int		where_to;

	if (n > find_max(stack) || n < find_min(stack, find_size(stack)))
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

/**
 * Pasa la cima de a a b en su sitio, para que b siga de mayor a menor.
 */
static void	order_chaos(t_ps *ps)
{
	int	where_to;

	if (ps->a == NULL)
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

/**
 * Recorre a una vez: deja en a los que van en orden creciente (ra) y manda
 * a b los que estorban.
 */
static void	push_chaos(t_ps *ps)
{
	int	current_max;
	int	size;
	int	i;

	if (ps->a == NULL)
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

/**
 * Ordena a cuando hay poco desorden: separa los que estorban en b y luego
 * mete cada uno en su hueco de a. Coste O(n * k), k = numeros que van a b.
 */
void	sort_little_chaos(t_ps *ps)
{
	int	first;
	int	last;

	if (has_two(ps->a) == 0)
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
