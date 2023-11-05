/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 04:21:12 by asuc              #+#    #+#             */
/*   Updated: 2023/11/05 05:26:18 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbr_arg(const char *format)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (format[i])
	{
		if ((format[i] == '%') && (format[i +1] == 'c'
				|| format[i +1] == 's' || format[i +1] == 'p'
				|| format[i +1] == 'd' || format[i +1] == 'i'
				|| format[i +1] == 'u' || format[i +1] == 'x'
				|| format[i +1] == 'X' || format[i +1] == '%'))
		{
			count++;
			i++;
		}
		i++;
	}
	return (count);
}

// ajout de la lst de tout les index des "conversions" et suppresion des %c %s %p %d %i %u %x %X %% dans le format
int	*index_type(char **format, int count)
{
	int	i;
	int	*tab_index;
	int	j;

	i = 0;
	j = 0;
	tab_index = ft_calloc(sizeof(int), count + 1);
	while (*format[i])
	{
		if ((*format[i] == '%') && (*format[i +1] == 'c'
				|| *format[i +1] == 's' || *format[i +1] == 'p'
				|| *format[i +1] == 'd' || *format[i +1] == 'i'
				|| *format[i +1] == 'u' || *format[i +1] == 'x'
				|| *format[i +1] == 'X' || *format[i +1] == '%'))
		{
			update_format(format, i);
			tab_index[j] = i - 1;
			i++;
			j++;
		}
		i++;
	}
	return (tab_index);
}

// update du format en supprimant les %c %s %p %d %i %u %x %X %% et en recollant le reste de la string
void	update_format(char **format, int index)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;

	i = 0;
	j = 0;
	len = ft_strlen(*format);
	tmp = ft_calloc(sizeof(char), len + 1);
	while (i < index - 1)
	{
		tmp[j] = (*format)[i];
		i++;
		j++;
	}
	i += 2;
	while ((*format)[i])
	{
		tmp[j] = (*format)[i];
		i++;
		j++;
	}
	free(*format);
	*format = tmp;
}

int	print_format(const char *format, int index, va_list arg)
{
	int	ret;

	ret = 0;
	if (format[index] == 'c')
		ret = print_char(va_arg(arg, char));
	else if (format[index] == 's')
		ret = print_string(va_arg(arg, char *));
	else if (format[index] == 'p')
		ret = print_pointer(va_arg(arg, void *));
	else if (format[index] == 'd' || format[index] == 'i')
		ret = print_decimal(va_arg(arg, int));
	else if (format[index] == 'u')
		ret = print_unsigned_int(va_arg(arg, unsigned int));
	else if (format[index] == 'x')
		ret = print_hexa(va_arg(arg, unsigned int));
	else if (format[index] == 'X')
		ret = print_hexa_maj(va_arg(arg, unsigned int));
	else if (format[index] == '%')
		ret = ft_putchar_fd('%', 1);
	return (ret);
}

int	to_print(const char *format, int *tab_index, int count, va_list arg)
{
	int	i;
	
	int	j;
	int	ret;

	i = 0;
	j = 0;
	ret = 0;
	while (i < count)
	{
		while (j != tab_index[i])
		{
			ft_putchar_fd(format[j], 1);
			ret++;
			j++;
		}
		ret = print_format(format, tab_index[i], arg);
		i++;
	}
}
