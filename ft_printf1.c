/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 04:46:05 by asuc              #+#    #+#             */
/*   Updated: 2023/11/05 20:25:34 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_numlen_base(long long int n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

void	neg_nbr_base(unsigned long long int n, int len, char **str, int base)
{
	(*str) = ft_calloc((len + 1), sizeof(char));
	if ((*str) == NULL)
		return ;
	(*str)[0] = '-';
	len--;
	while (len > 0)
	{
		(*str)[len] = "0123456789abcdef"[n % base];
		n /= base;
		len--;
	}
}

char	*ft_itoa_base(long long int n, int base)
{
	int						len;
	char					*str;
	unsigned long long int	nbr;

	if (base < 2 || base > 16)
		return (NULL);
	len = ft_numlen_base(n, base);
	if (n < 0)
	{
		nbr = -n;
		neg_nbr_base(nbr, len, &str, base);
		return (str);
	}
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

