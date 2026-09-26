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

/**
 * Una pasada del radix: los nodos con el bit a 0 van a b, los de 1 se
 * quedan en a.
 * @param bit numero de bit a mirar (0 = el de menos peso)
 */
static void	sort_bit(t_ps *ps, int bit)
{
	int	size;
	int	i;

	size = find_size(ps->a);
	i = 0;
	while (i < size)
	{
		if (((ps->a->index >> bit) & 1) == 1)
			ra(ps);
		else
			pb(ps);
		i++;
	}
}

/**
 * Ordena a por radix binario (--complex, O(n log n)).
 * Una pasada por cada bit del mayor index; tras cada una, todo vuelve a a.
 */
void	radix_sort(t_ps *ps)
{
	int	max_bits;
	int	bit;

	if (ps == NULL || has_two(ps->a) == 0)
		return ;
	max_bits = 0;
	while ((find_max(ps->a) >> max_bits) != 0)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		sort_bit(ps, bit);
		while (ps->b != NULL)
			pa(ps);
		bit++;
	}
}
