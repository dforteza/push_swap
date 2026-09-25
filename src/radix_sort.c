/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatrizdocarmo <beatrizdocarmo@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 23:35:32 by beatrizdoca       #+#    #+#             */
/*   Updated: 2026/09/25 17:12:13 by beatrizdoca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_bit(t_ps *ps, int current_bit)
{
	int	current_node;
	int	size;

	if (ps == NULL || has_two(ps->a) == 0)
		return ;
	size = find_size(ps->a);
	current_node = 0;
	while (current_node < size)
	{
		if (((ps->a->index >> current_bit) & 1) == 1)
			ra(ps);
		else
			pb(ps);
		current_node++;
	}
}

//pendiente de revisar porque
//queda más elocuente con arreglo a size
//ya quitando de vez a find_max
void	radix_sort(t_ps *ps)
{
	int	max;
	int	max_bits;
	int	current_bit;

	if (ps == NULL || has_two(ps->a) == 0)
		return ;
	max = find_max(ps->a);
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	current_bit = 0;
	while (current_bit < max_bits)
	{
		sort_bit(ps, current_bit);
		while (ps->b != NULL)
			pa(ps);
		current_bit++;
	}
}
