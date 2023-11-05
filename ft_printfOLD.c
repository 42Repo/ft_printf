/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:55:40 by asuc              #+#    #+#             */
/*   Updated: 2023/11/05 05:07:06 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	print_string(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i);
}

// • %p The void * pointer argument has to be printed in hexadecimal format.
int	print_pointer(void *ptr)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa_base((unsigned long long)ptr, 16);
	printf("str = %s\n", str);
	ft_putstr_fd("0x", 1);
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i + 2);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		*tab_index;
	int		count;

	count = 0;
	tab_index = NULL;
	i = nbr_arg(format);
	tab_index = index_type((char **)&(format), i);
	va_start(arg, format);
	to_print(format, tab_index, i, arg);
	va_end(arg);
	return (0);
}

int main()
{
	ft_printf("oasjidpisad%sd", "dasodasda", "dasdasdasd");
	//printf("%s", (char *) 0);
}
