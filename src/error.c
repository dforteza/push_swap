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

/**
 * Libera el array de ft_split y cada una de sus cadenas.
 * @param nums array terminado en NULL
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

/**
 * Libera todos los nodos de una pila.
 * @param stack pila a liberar (puede estar vacia)
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

/**
 * Libera todo, escribe "Error" por stderr y termina con exit(1).
 * @param nums split pendiente de liberar, o NULL
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
