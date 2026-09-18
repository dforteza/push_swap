/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 17:15:04 by difortez          #+#    #+#             */
/*   Updated: 2026/09/18 17:50:29 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Devuelve 1 si arg es exactamente flag, 0 si no.
** Compara ft_strlen(flag) + 1 caracteres para incluir el '\0':
** asi "--simplex" no pasa como "--simple".
*/
static int	is_flag(char *arg, char *flag)
{
    int len;

    len = ft_strlen(arg);
    if (!(ft_strncmp(arg, "--simple", len + 1) == 0 || ft_strncmp("--medium", arg, len + 1) == 0 || ft_strncmp("--complex", arg, len + 1) == 0))
        return (0);
    return (1);
    
}

/*
** Guarda la estrategia en ps->strategy.
** Si ya habia una (ps->strategy != NONE) devuelve -1 (dos estrategias).
** Si no, la guarda y devuelve 0.
*/
static int	set_strategy(t_ps *ps, int strategy)
{
    
}

/*
** Mira cual de los 5 flags es arg y actua:
**   --simple, --medium, --complex, --adaptive -> set_strategy
**   --bench -> ps->bench = 1 (si ya era 1 -> -1, flag repetido)
**   cualquier otro -> -1 (flag inexistente)
** Devuelve 0 si todo va bien, -1 si hay error.
*/
static int	read_flag(t_ps *ps, char *arg)
{
    
}

/*
** Recorre av desde i = 1 mientras av[i] empiece por "--".
** Para cada flag llama a read_flag; si devuelve -1 -> devuelve -1.
** Al terminar, si ps->strategy sigue en NONE -> ADAPTIVE.
** Devuelve i: el primer argumento con numeros (o -1 si hubo error).
** Un flag despues de un numero lo detecta el parseo, no esta funcion.
*/
int			parse_flags(int ac, char **av, t_ps *ps)
{
    
}