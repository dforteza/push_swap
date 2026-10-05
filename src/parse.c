/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 17:15:15 by difortez          #+#    #+#             */
/*   Updated: 2026/10/04 11:46:14 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (res > INT_MAX)
			break ;
		i++;
	}
	return (res * sign);
}

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

static void	add_node(t_ps *ps, char **nums, long n)
{
	t_node	*new;
	t_node	*tmp;

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
		tmp = ps->a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

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
			if (is_valid(nums[j]) == 0)
				error_exit(ps, nums);
			n = ft_atol(nums[j]);
			if (!(n >= INT_MIN && n <= INT_MAX))
				error_exit(ps, nums);
			if (is_duplicate(ps->a, n) == 1)
				error_exit(ps, nums);
			add_node(ps, nums, n);
			j++;
		}
		free_split(nums);
		i++;
	}
}
