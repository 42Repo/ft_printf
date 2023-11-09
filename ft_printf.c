/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_printf.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: asuc <asuc@student.42angouleme.fr>		 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/11/05 17:19:23 by asuc			  #+#	#+#			 */
/*   Updated: 2023/11/09 17:35:30 by asuc			 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "includes/ft_printf.h"



int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;

	if (!format)
		return (-1);
	va_start(arg, format);
	count = process_format(format, arg);
	va_end(arg);
	return (count);
}

int	process_format(const char *format, va_list arg)
{
	int	i;
	int	count;
	int	ret;
	int err;

	i = 0;
	count = 0;
	err = 0;
	while (format[i])
	{
		ret = handle_character(format, &i, arg, &err);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	return (count);
}

int	handle_character(const char *format, int *index, va_list arg, int *err)
{
	int	ret;

	if (format[*index] == '%')
		ret = handle_percent(format, index, arg, err);
	else
		ret = ft_putchar_fd(format[*index], 1);
	(*index)++;
	return (ret);
}

int	handle_percent(const char *format, int *index, va_list arg, int *err)
{
	int	ret;

	ret = 0;
	if (is_format(format[*index + 1]) == 0)
		(*err)++;
	ret += print_format(format, *index + 1, arg);
	if ((*err) == 1 && ret == 0 && format[*index + 1] == 0)
		return (-1);
	if (ret == 0)
		ret = ft_putchar_fd(format[*index], 1);
	else
		(*index)++;
	return (ret);
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
