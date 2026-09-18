/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:32:17 by dforteza          #+#    #+#             */
/*   Updated: 2026/06/18 12:50:40 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *block, int c, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((unsigned char *)block)[i] = (unsigned char)c;
		i++;
	}
	return (block);
}
