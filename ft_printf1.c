/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 04:46:05 by asuc              #+#    #+#             */
/*   Updated: 2023/11/09 17:53:27 by asuc             ###   ########.fr       */
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

int	print_hex_other(unsigned int nb, int mode)
{
	char	*str;
	int		ret;

	if (!nb)
		return (0);
	ret = 0;
	if (nb == 0)
		return (ft_putstr_fd("0", 1));
	str = ft_itoa_base_hex(nb, 16, mode);
	ret += ft_putstr_fd(str, 1);
	free(str);
	return (ret);
}

int	print_format(const char *format, int index, va_list arg)
{
	int	ret;

	ret = 0;
	if (format[index] == 'c')
		ret = ft_putchar_fd(va_arg(arg, int), 1);
	else if (format[index] == 's')
		ret = ft_putstr_fd(va_arg(arg, char *), 1);
	else if (format[index] == 'p')
		ret = print_hex(va_arg(arg, unsigned long long));
	else if (format[index] == 'd' || format[index] == 'i')
		ret = ft_putnbr_fd(va_arg(arg, int), 1);
	else if (format[index] == 'u')
		ret = ft_putnbr_fd(va_arg(arg, unsigned int), 1);
	else if (format[index] == 'x')
		ret = print_hex_other(va_arg(arg, long long), 2);
	else if (format[index] == 'X')
		ret = print_hex_other(va_arg(arg, long long), 3);
	else if (format[index] == '%')
		ret = ft_putchar_fd('%', 1);
	return (ret);
}

