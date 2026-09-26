/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 17:15:15 by difortez          #+#    #+#             */
/*   Updated: 2026/09/20 14:42:00 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Comprueba que str sea un entero: signo opcional y solo digitos.
 * @return 1 si es valido, 0 si no
 */
static int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

/**
 * Convierte str a long; para al pasar de INT_MAX para no desbordar.
 * @param str cadena ya validada por is_valid
 * @return el numero, o uno fuera del rango int si era demasiado grande
 */
static long	ft_atol(char *str)
{
	int		i;
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		if (res > 2147483648L)
			break ;
		i++;
	}
	return (res * sign);
}

/**
 * Comprueba si n ya esta en la pila a.
 * @return 1 si esta, 0 si no
 */
static int	is_duplicate(t_node *a, long n)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

/**
 * Crea un nodo con value = n y lo anade al final de a.
 * @param nums split actual, para liberarlo si falla malloc
 */
static void	add_node(t_ps *ps, char **nums, long n)
{
	t_node	*new;
	t_node	*temp;

	new = malloc(sizeof(t_node));
	if (!new)
		error_exit(ps, nums);
	new->value = (int)n;
	new->index = 0;
	new->next = NULL;
	if (!ps->a)
		ps->a = new;
	else
	{
		temp = ps->a;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

/**
 * Valida cada numero de av y construye la pila a; si falla, error_exit.
 * @param i posicion del primer numero en av
 */
void	parse_numbers(t_ps *ps, int ac, char **av, int i)
{
	char	**nums;
	long	n;
	int		j;

	while (i < ac)
	{
		nums = ft_split(av[i], ' ');
		if (!nums || !nums[0])
			error_exit(ps, nums);
		j = 0;
		while (nums[j])
		{
			if (!is_valid(nums[j]))
				error_exit(ps, nums);
			n = ft_atol(nums[j]);
			if (n < INT_MIN || n > INT_MAX)
				error_exit(ps, nums);
			if (is_duplicate(ps->a, n))
				error_exit(ps, nums);
			add_node(ps, nums, n);
			j++;
		}
		free_split(nums);
		i++;
	}
}
