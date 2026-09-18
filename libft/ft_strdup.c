/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:46:36 by dforteza          #+#    #+#             */
/*   Updated: 2026/06/18 18:29:31 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		len;

	len = ft_strlen(src);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, src, len + 1);
	return (dest);
}
