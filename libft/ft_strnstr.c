/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:29:38 by dforteza          #+#    #+#             */
/*   Updated: 2026/06/18 16:11:53 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t size)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < size)
	{
		j = 0;
		while ((haystack[i + j] == needle[j] && (i + j) < size))
		{
			j++;
			if (j == ft_strlen(needle))
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
