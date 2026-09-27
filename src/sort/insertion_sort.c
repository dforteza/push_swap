/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatrizdocarmo <beatrizdocarmo@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 13:29:01 by beatrizdoca       #+#    #+#             */
/*   Updated: 2026/09/27 03:08:08 by beatrizdoca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//pendiente revisar, son 2:30 y ya no sirvo de mucho
//falta ver funcionar
//pero entiendo que la complejidad no es O(n+k)
//sino algo entre ello y 0(n.k)
//más bien O(n.k) precisamente por la vuelta en k
//porque da vuelta en el pequeño caos
//aunque la preordenacion de push_chaos mitiga
//lo ideal seria la lis con calculo de coste
//de seguir con mejorar los algoritmos me pongo con ello
//ya se hacen los nombres más normales también

//cuestión de línea
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

int	where_to(t_node *stack, int n)
{
	t_node	*current;
	int		where;

	if (n > find_max(stack))
		return (find_min(stack));
	current = stack;
	where = find_max(stack) + 1;
	while (current != NULL)
	{
		if (current->index > n && current->index < where)
			where = current->index;
		current = current->next;
	}
	return (where);
}

//creo que tampoco soluciona el probema de la complejidad
//itenta contornar, pero da vuelta en el pequeño caos
//también hace falta verlo funcionar
void	sort_little_chaos(t_ps *ps)
{
	int	max;

	if (ps == NULL || has_two(ps->a) == 0)
		return ;
	move_to_top(ps, 'a', find_place(ps->a, 0));
	push_chaos(ps);
	while (ps->b != NULL)
	{
		max = find_max(ps->b);
		move_to_top(ps, 'b', find_place(ps->b, max));
		move_to_top(ps, 'a', find_place(ps->a, where_to(ps->a, max)));
		pa(ps);
	}
	find_order(ps);
}
