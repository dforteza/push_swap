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

/*
** Devuelve 1 si str tiene forma de numero entero, 0 si no.
** Acepta un '+' o '-' inicial y exige al menos un digito detras;
** a partir de ahi todos los caracteres deben ser digitos.
** Solo mira la forma: no dice cuanto vale ni si cabe en un int.
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

/*
** Convierte str a long. Da por hecho que is_valid ya lo ha validado.
** Corta el bucle en cuanto res pasa de 2147483648 para no desbordar
** el long con entradas de muchos digitos: el valor que devuelve sigue
** siendo mayor que INT_MAX, que es lo unico que hace falta saber.
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

/*
** Devuelve 1 si n ya esta en la pila a, 0 si no.
** Recorre la lista comparando value. Con la lista vacia devuelve 0
** sin dar ninguna vuelta.
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

/*
** Crea un nodo con value = n (index lo rellena normalize despues) y lo
** engancha al final de la pila a. Dos casos: si la lista esta vacia el
** nodo pasa a ser la cabeza; si no, recorre hasta el ultimo y lo cuelga.
** Si falla el malloc llama a error_exit, que libera todo y sale.
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

/*
** Recorre av desde i (primer argumento que no es flag) y parte cada uno
** por espacios, porque un solo argumento puede traer varios numeros.
** Cada trozo pasa por la cadena: is_valid -> ft_atol -> rango de int ->
** is_duplicate -> add_node. Cualquier fallo llama a error_exit.
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
