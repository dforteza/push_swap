/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 12:00:00 by difortez          #+#    #+#             */
/*   Updated: 2026/09/22 12:00:00 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Escribe la operacion por stdout y suma uno a su contador.
 * @param name nombre con salto de linea, p. ej. "sa\n"
 * @param op   posicion del contador (SA, PB...)
 */
void	log_op(t_ps *ps, char *name, int op)
{
	ft_putstr_fd(name, 1);
	ps->count[op]++;
}
