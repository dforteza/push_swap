/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:11:11 by dforteza          #+#    #+#             */
/*   Updated: 2026/06/19 16:52:16 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t size)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)to;
	s = (const unsigned char *)from;
	if (!to && !from)
		return (NULL);
	if (d < s)
		ft_memcpy(to, from, size);
	else
	{
		while (size--)
			d[size] = s[size];
	}
	return (to);
}
