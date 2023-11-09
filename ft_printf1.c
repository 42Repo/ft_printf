/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 04:46:05 by asuc              #+#    #+#             */
/*   Updated: 2023/11/09 14:52:45 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_num_len_base(unsigned long int n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(unsigned long int n, int base)
{
	int		len;
	char	*str;

	if (base < 2 || base > 16)
		return (NULL);
	len = ft_num_len_base(n, base);
	str = ft_calloc(sizeof(char), (len + 1));
	if (str == NULL)
		return (NULL);
	len--;
	while (len >= 0)
	{
		str[len] = "0123456789abcdef"[n % base];
		n /= base;
		len--;
	}
	return (str);
}

char	*ft_itoa_base_hex(unsigned int n, int base, int mode)
{
	int		len;
	char	*str;

	if (base < 2 || base > 16)
		return (NULL);
	len = ft_num_len_base(n, base);
	str = ft_calloc(sizeof(char), (len + 1));
	if (str == NULL)
		return (NULL);
	len--;
	while (len >= 0)
	{
		if (mode == 3)
			str[len] = "0123456789ABCDEF"[n % base];
		else
			str[len] = "0123456789abcdef"[n % base];
		n /= base;
		len--;
	}
	return (str);
}
