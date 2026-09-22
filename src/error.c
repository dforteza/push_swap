/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 17:15:06 by difortez          #+#    #+#             */
/*   Updated: 2026/09/21 15:42:39 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Libera el array que devuelve ft_split: primero cada cadena y
** despues el array. No necesita contador porque ft_split deja un
** NULL al final, igual que argv.
*/
void	free_split(char **nums)
{
	int	i;

	i = 0;
	while (nums[i])
	{
		free(nums[i]);
		i++;
	}
	free(nums);
}

/*
** Libera todos los nodos de una pila. Guarda el next en tmp antes de
** liberar el nodo: despues del free ya no se puede leer su contenido.
** Con stack a NULL el bucle no entra y no hace nada.
*/
void	free_stack(t_node *stack)
{
	t_node	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

/*
** Salida unica de error: libera el split (si lo hay) y las dos pilas,
** escribe Error por la salida de error y termina el programa.
** nums es NULL cuando el error salta antes de haber hecho el split.
*/
void	error_exit(t_ps *ps, char **nums)
{
	if (nums)
		free_split(nums);
	free_stack(ps->a);
	free_stack(ps->b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
