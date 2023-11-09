/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:19:23 by asuc              #+#    #+#             */
/*   Updated: 2023/11/09 16:30:34 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		count;
	int		ret;
	int		err;

	err = 0;
	count = 0;
	i = 0;
	if (!format)
		return (-1);
	va_start(arg, format);
	while (format[i])
	{
		ret = 0;
		if (format[i] == '%')
		{
			if (is_format(format[i + 1]) == 0)
				err++;
			ret += print_format(format, i + 1, arg);
			if (err == 1 && ret == 0 && format[i + 1] == 0)
				return (-1);
			if (ret == 0)
				ret += ft_putchar_fd(format[i], 1);
			else
				i++;
		}
		else
			ret += ft_putchar_fd(format[i], 1);
		i++;
		count += ret;
	}
	va_end(arg);
	return (count);
}

int	print_hex(unsigned long long nb)
{
	char	*str;
	int		ret;

	ret = 0;
	if (!nb)
		return (0);
	if (nb == 0)
	{
		ret = ft_putstr_fd("(nil)", 1);
		return (ret);
	}
	ret += ft_putstr_fd("0x", 1);
	str = ft_itoa_base(nb, 16);
	ret += ft_putstr_fd(str, 1);
	free(str);
	return (ret);
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

int	is_format(char c)
{
	int	i;

	i = 0;
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}
