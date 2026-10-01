/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 17:10:01 by difortez          #+#    #+#             */
/*   Updated: 2026/10/01 22:16:27 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Apunta en ps->used el algoritmo que toca segun n, flag y desorden.
 */
static void	choose_strategy(t_ps *ps)
{
	if (find_size(ps->a) <= 5)
		ps->used = SMALL;
	else
	{
		if (ps->strategy != ADAPTIVE)
			ps->used = ps->strategy;
		else
		{
			if (ps->disorder < 0.2)
				ps->used = LINEAR;
			else
				ps->used = COMPLEX;
		}
	}
}

/**
 * Elige la estrategia y ejecuta el algoritmo correspondiente.
 */
static void	run_strategy(t_ps *ps)
{
	if (ps->used == SMALL)
		small_sort(ps);
	else if (ps->used == LINEAR)
		sort_little_chaos(ps);
	else if (ps->used == SIMPLE)
		selection_sort(ps);
	else if (ps->used == MEDIUM)
		chunk_sort(ps);
	else if (ps->used == COMPLEX)
		quick_sort(ps);
}

/**
 * Flags, numeros, normalizar, desorden, ordenar y liberar.
 * @return (0); los errores salen antes por error_exit
 */
int	main(int ac, char **av)
{
	t_ps	ps;
	int		i;

	ft_bzero(&ps, sizeof(ps));
	ps.strategy = NONE;
	i = parse_flags(&ps, ac, av);
	if (i == -1)
		error_exit(&ps, NULL);
	parse_numbers(&ps, ac, av, i);
	if (ps.a)
	{
		normalize(ps.a);
		ps.disorder = calculate_disorder(ps.a);
		choose_strategy(&ps);
		if (!is_sorted(ps.a))
			run_strategy(&ps);
		if (ps.bench == 1)
			print_bench(&ps);
		free_stack(ps.a);
		free_stack(ps.b);
	}
	return (0);
}
