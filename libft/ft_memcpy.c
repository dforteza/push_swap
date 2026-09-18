/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:01:20 by dforteza          #+#    #+#             */
/*   Updated: 2026/06/19 16:52:15 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t size)
{
	size_t	i;

	if (!to && !from && size > 0)
		return (NULL);
	if (to == from || size == 0)
		return (to);
	i = 0;
	while (i < size)
	{
		((unsigned char *)to)[i] = ((const unsigned char *)from)[i];
		i++;
	}
	return (to);
}
