/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:10:44 by dforteza          #+#    #+#             */
/*   Updated: 2026/06/18 18:24:12 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t eltsize)
{
	void	*p;

	if (eltsize != 0 && count > SIZE_MAX / eltsize)
		return (NULL);
	p = (void *)malloc(count * eltsize);
	if (!p)
		return (NULL);
	ft_bzero(p, count * eltsize);
	return (p);
}
