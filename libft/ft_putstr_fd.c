/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 23:34:53 by asuc              #+#    #+#             */
/*   Updated: 2023/11/10 04:13:45 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *str, int fd)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (str[i])
	{
		ret += ft_putchar_fd(str[i], fd);
		i++;
	}
	return (ret);
}
