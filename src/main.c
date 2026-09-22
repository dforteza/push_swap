/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 17:10:01 by difortez          #+#    #+#             */
/*   Updated: 2026/09/22 17:46:52 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
** 1. PROCESAR FLAGS          5. ELEGIR ALGORITMO
** 2. PARSEAR NUMEROS         6. ORDENAR
** 3. NORMALIZAR              7. SI BENCH -> SACAR INFO
** 4. CALCULAR DESORDEN       8. LIBERAR Y CERRAR
*/

/* TRAZAS: print_stack y trace se borran enteras en la entrega. */
static void	print_stack(t_node *stack, char *name)
{
	fprintf(stderr, "  %s: [", name);
	while (stack)
	{
		fprintf(stderr, "%d", stack->index);
		if (stack->next)
			fprintf(stderr, " ");
		stack = stack->next;
	}
	fprintf(stderr, "]\n");
}

/* TRAZAS */
static void	trace(t_ps *ps, char *tag)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < N_OPS)
	{
		total += ps->count[i];
		i++;
	}
	fprintf(stderr, "--- %s | n=%d | estrategia=%d | desorden=%.4f | %d ops\n",
		tag, find_size(ps->a), ps->strategy, ps->disorder, total);
	print_stack(ps->a, "a");
	print_stack(ps->b, "b");
}

static void	run_strategy(t_ps *ps)
{
	if (ps->strategy == SIMPLE)
		selection_sort(ps);
	else
		fprintf(stderr, "TBD...\n");
}

int	main(int ac, char **av)
{
	t_ps	ps;
	int		i;

	ft_bzero(&ps, sizeof(ps));
	ps.strategy = NONE;
	i = parse_flags(ac, av, &ps);
	if (i == -1)
		error_exit(&ps, NULL);
	parse_numbers(&ps, ac, av, i);
	normalize(&ps);
	if (is_sorted(ps.a))
	{
		free_stack(ps.a);
		return (0);
	}
	ps.disorder = compute_disorder(ps.a);
	trace(&ps, "ANTES");
	run_strategy(&ps);
	trace(&ps, "DESPUES");
	free_stack(ps.a);
	free_stack(ps.b);
	return (0);
}
