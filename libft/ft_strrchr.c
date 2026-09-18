/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:33:40 by dforteza          #+#    #+#             */
/*   Updated: 2026/09/14 13:20:55 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*p;

	i = 0;
	c = (unsigned char)c;
	p = NULL;
	while (str[i])
	{
		if (str[i] == c)
			p = (char *)&str[i];
		i++;
	}
	if (c == '\0')
		p = (char *)&str[i];
	return (p);
}
