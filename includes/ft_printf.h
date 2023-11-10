/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:49:06 by asuc              #+#    #+#             */
/*   Updated: 2023/11/10 18:21:39 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *format, ...);
char	*ft_itoa_base(unsigned long n, int base);
int		ft_num_len_base(unsigned long n, int base);
int		print_hex(unsigned long nb);
int		print_hex_other(unsigned int nb, int mode);
int		print_format(const char *format, int index, va_list arg);
char	*ft_itoa_base_hex(unsigned int n, int base, int mode);
int		is_format(char c);
int		process_format(const char *format, va_list arg);
int		handle_percent(const char *format, int *index, va_list arg, int *err);
int		handle_character(const char *format, int *index, va_list arg, int *err);

#endif
