/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:49:06 by asuc              #+#    #+#             */
/*   Updated: 2023/11/07 23:53:34 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *format, ...);
char	*ft_itoa_base(unsigned long int n, int base);
int		ft_num_len_base(unsigned long int n, int base);
int		print_hex(unsigned long long nb);
int		print_hex_other(unsigned int nb, int mode);
int		print_format(const char *format, int index, va_list arg);
int		ft_num_len_base_hex(unsigned int n, int base);

#endif
