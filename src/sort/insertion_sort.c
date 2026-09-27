/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatrizdocarmo <beatrizdocarmo@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 13:29:01 by beatrizdoca       #+#    #+#             */
/*   Updated: 2026/09/28 01:32:49 by beatrizdoca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//la complejidad no es O(n+k)
//O(n.k) precisamente porque da vuelta en el pequeño caos

//voy metiendo abajo o arriba para intentar disminuir operaciones 
//pero si me caen números pequeños o grandes al principio y queda en la mitad
//del stack, no sé si exponencial pero demasiadas operaciones
//(subía y bajaba demasiado entre huecos)
//mal mal, que pensaba que no sabía testear
//así que la idea es que, en lugar de ordenar al pasar,
//se ordene al insert en b
//(así pasa efectivamente una sola vez por a, como se esperaba que lo hiciera)
//que en realidad es lo que debería hacer el merge
//y lo que parecía un buen atajo era pereza disfrazada
//--sorry

//novamente super tarde, mañana por la mañana lo tengo
//falta revisar con lucidez, verlo funcionar
//y adaptar nombres y cosas de la norma
//por ahora lo he dejado asi por recordarme a que me referia conmigo misma
int	increasing_where(t_node *stack, int n)
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

int	decreasing_where(t_node *stack, int n)
{
	t_node	*current;
	int		where;

	if (n > find_max(stack) || n < find_min(stack))
		return (find_max(stack));
	current = stack;
	where = -1;
	while (current != NULL)
	{
		if (current->index < n && current->index > where)
			where = current->index;
		current = current->next;
	}
	return (where);
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
		{
			if (find_size(ps->b) < 2)
			{
				pb(ps);
				if (find_size(ps->b) == 2 && ps->b->index < ps->b->next->index)
					sb(ps);
			}
			else
			{
				move_to_top(ps, 'b', find_place(ps->b, decreasing_where(ps->b, ps->a->index)));
				pb(ps);
			}
		}
		else
		{
			current_max = ps->a->index;
			ra(ps);
		}
		i++;
	}
}

void	sort_little_chaos(t_ps *ps)
{
	if (ps == NULL || has_two(ps->a) == 0)
		return ;
	move_to_top(ps, 'a', find_place(ps->a, 0));
	push_chaos(ps);
	while (ps->b != NULL)
	{
		move_to_top(ps, 'a', find_place(ps->a, increasing_where(ps->a, ps->b->index)));
		pa(ps);
	}
	move_to_top(ps, 'a', find_place(ps->a, 0));
}

/*void	push_chaos(t_ps *ps)
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
}*/

