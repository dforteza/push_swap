/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 17:10:01 by difortez          #+#    #+#             */
/*   Updated: 2026/09/19 14:06:48 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_ps	ps;
	
	ft_bzero(&ps, sizeof(ps));
	ps.strategy = NONE;
	int i = parse_flags(ac, av, &ps);

	printf("i: %d || strategy: %d, bench : %d", i, ps.strategy, ps.bench);
	return (0);
}