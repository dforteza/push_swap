/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 17:15:04 by difortez          #+#    #+#             */
/*   Updated: 2026/09/28 17:10:24 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_flag(char *arg, char *flag)
{
	int	len;

	len = ft_strlen(flag);
	if (ft_strncmp(arg, flag, len + 1) != 0)
		return (0);
	return (1);
}

static int	set_strategy(t_ps *ps, int strategy)
{
	if (ps->strategy != NONE)
		return (-1);
	ps->strategy = strategy;
	return (0);
}

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

int	parse_flags(t_ps *ps, int ac, char **av)
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
