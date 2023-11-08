/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:38:59 by asuc              #+#    #+#             */
/*   Updated: 2023/11/07 23:11:00 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	i;
	int *test;
	int gay;
	char *str;

	test = &gay;
	i = 0;
	str = NULL;
	i = ft_printf(str, str);
	printf("\ni = %ed\n", i);
	i = printf(str);
	printf("\ni = %d\n", i);
	return (0);
}
