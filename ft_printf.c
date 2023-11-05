/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:19:23 by asuc              #+#    #+#             */
/*   Updated: 2023/11/05 19:50:59 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += print_format(format, i + 1, arg);
			i++;
		}
		else
			count += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(arg);
	return (count);
}

// print_hex for %x and %X and %p
int	print_hex(long long nb)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa_base(nb, 16);
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i);
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
		ret = print_hex(va_arg(arg, long long));
	else if (format[index] == 'd' || format[index] == 'i')
		ret = ft_putnbr_fd(va_arg(arg, int), 1);
	else if (format[index] == 'u')
		ret = ft_putnbr_fd(va_arg(arg, unsigned int), 1);
	else if (format[index] == 'x')
		ret = print_hex(va_arg(arg, long long));
	else if (format[index] == 'X')
		ret = print_hex(va_arg(arg, long long));
	else if (format[index] == '%')
		ret = ft_putchar_fd('%', 1);
	return (ret);
}
