/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:22:30 by dforteza          #+#    #+#             */
/*   Updated: 2026/06/17 19:43:50 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*p;

	i = 0;
	c = (unsigned char)c;
	p = NULL;
	while (str[i])
	{
		if ((unsigned char)str[i] == c)
		{
			p = (char *)&str[i];
			break ;
		}
		i++;
	}
	if (c == '\0')
		p = (char *)&str[i];
	return (p);
}
