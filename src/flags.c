/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 17:15:04 by difortez          #+#    #+#             */
/*   Updated: 2026/09/20 14:44:13 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Compara arg con flag incluyendo el '\0': "--simplex" no vale.
 * @param arg  argumento de av
 * @param flag flag esperado, p. ej. "--simple"
 * @return 1 si son iguales, 0 si no
 */
static int	is_flag(char *arg, char *flag)
{
	int	len;

	len = ft_strlen(flag);
	if (ft_strncmp(arg, flag, len + 1) != 0)
		return (0);
	return (1);
}

/**
 * Guarda la estrategia en ps, si no habia otra ya.
 * @param strategy SIMPLE, MEDIUM, COMPLEX o ADAPTIVE
 * @return 0 si va bien, -1 si ya habia una estrategia
 */
static int	set_strategy(t_ps *ps, int strategy)
{
	if (ps->strategy != NONE)
		return (-1);
	ps->strategy = strategy;
	return (0);
}

/**
 * Identifica el flag y lo aplica a ps.
 * @param arg argumento que empieza por "--"
 * @return 0 si va bien, -1 si no existe o esta repetido
 */
static int	read_flag(t_ps *ps, char *arg)
{
	if (is_flag(arg, "--simple"))
		return (set_strategy(ps, SIMPLE));
	else if (is_flag(arg, "--medium"))
		return (set_strategy(ps, MEDIUM));
	else if (is_flag(arg, "--complex"))
		return (set_strategy(ps, COMPLEX));
	else if (is_flag(arg, "--adaptive"))
		return (set_strategy(ps, ADAPTIVE));
	else if (is_flag(arg, "--bench"))
	{
		if (ps->bench == 1)
			return (-1);
		ps->bench = 1;
		return (0);
	}
	return (-1);
}

/**
 * Lee los flags del principio de av; sin estrategia, usa ADAPTIVE.
 * @return posicion del primer numero en av, o -1 si hay error
 */
int	parse_flags(int ac, char **av, t_ps *ps)
{
	int	i;

	i = 1;
	while (i < ac && ft_strncmp(av[i], "--", 2) == 0)
	{
		if (read_flag(ps, av[i]) == -1)
			return (-1);
		i++;
	}
	if (ps->strategy == NONE)
		ps->strategy = ADAPTIVE;
	return (i);
}
