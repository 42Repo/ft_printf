/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:49:06 by asuc              #+#    #+#             */
/*   Updated: 2023/11/05 05:09:16 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
int		nbr_arg(const char *format);
int		*index_type(char **format, int count);
int		print_format(const char *format, int index, va_list arg);
void	to_print(const char *format, int *tab_index,
			int count, va_list arg);
int		print_char(char c);
int		print_string(char *str);
char	*ft_itoa_base(long long int n, int base);
void	neg_nbr_base(unsigned long long int n, int len,
			char **str, int base);
int		ft_numlen_base(long long int n, int base);
int		print_pointer(void *ptr);
char	*ft_itoa_base(long long int n, int base);
void	update_format(char **format, int index);



#endif
