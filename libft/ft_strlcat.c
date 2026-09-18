/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:42:58 by dforteza          #+#    #+#             */
/*   Updated: 2026/06/19 16:52:22 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	unsigned int	len_src;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (dest[j] && j < size)
		j++;
	len_dest = j;
	i = 0;
	while (src[i])
		i++;
	len_src = i;
	if (len_dest >= size || size == 0)
		return (size + len_src);
	i = 0;
	while (src[i] && ((j + 1) < size))
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (len_dest + len_src);
}
