/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 17:10:01 by difortez          #+#    #+#             */
/*   Updated: 2026/09/21 18:02:26 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/**
1. PROCESAR FLAGS
2. PARSEAR NÚMEROS
3. NORMALIZAR
4. CALCULAR DESORDEN
5. ELEGIR ALGORITMO
6. ORDENAR
7. SI BENCH → SACAR INFO
8. LIBERAR Y CERRAR
 */
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

	printf("DESORDEN: %f\n", ps.disorder);
	free_stack(ps.a);
	return (0);
}
