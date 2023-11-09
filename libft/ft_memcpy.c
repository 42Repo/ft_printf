/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 00:25:07 by asuc              #+#    #+#             */
/*   Updated: 2023/11/09 02:24:08 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	char		*d;
	const char	*s;

	s = source;
	d = destination;
	if (s == NULL && d == NULL)
		return (destination);
	while (size)
	{
		*d++ = *s++;
		size--;
	}
	return (destination);
}
