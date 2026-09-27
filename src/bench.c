/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 14:00:00 by difortez          #+#    #+#             */
/*   Updated: 2026/09/27 20:28:03 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Traduce ps->used a nombre y complejidad, p. ej. "medium O(n*sqrt(n))".
 */
static char	*strategy_name(int used)
{
	if (used == SMALL)
		return ("small O(1)");
	if (used == LINEAR)
		return ("linear O(n)");
	if (used == SIMPLE)
		return ("simple O(n^2)");
	if (used == MEDIUM)
		return ("medium O(n*sqrt(n))");
	if (used == COMPLEX)
		return ("complex O(n*log(n))");
	return ("unknown");
}

/**
 * Imprime el desorden como porcentaje con dos decimales, p. ej. 43.12%.
 */
static void	print_disorder(double disorder)
{
	int	percent;
	int	whole;
	int	decimals;

	percent = (int)(disorder * 10000 + 0.5);
	whole = percent / 100;
	decimals = percent % 100;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(whole, 2);
	ft_putstr_fd(".", 2);
	if (decimals < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(decimals, 2);
	ft_putstr_fd("%\n", 2);
}

/**
 * Suma las 11 cantidades de ps->count.
 */
static int	total_ops(t_ps *ps)
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
	return (total);
}

/**
 * Imprime cuantas veces se ha usado cada una de las 11 operaciones.
 */
static void	print_ops(t_ps *ps)
{
	static char	*names[N_OPS] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
		"rr", "rra", "rrb", "rrr"};
	int			i;

	i = 0;
	while (i < N_OPS)
	{
		ft_putstr_fd("[bench] ", 2);
		ft_putstr_fd(names[i], 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd(ps->count[i], 2);
		ft_putstr_fd("\n", 2);
		i++;
	}
}

/**
 * Imprime por stderr las metricas del modo --bench tras ordenar.
 */
void	print_bench(t_ps *ps)
{
	print_disorder(ps->disorder);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putendl_fd(strategy_name(ps->used), 2);
	ft_putstr_fd("[bench] total operations: ", 2);
	ft_putnbr_fd(total_ops(ps), 2);
	ft_putstr_fd("\n", 2);
	print_ops(ps);
}
