/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:38:59 by asuc              #+#    #+#             */
/*   Updated: 2023/11/07 22:07:55 by asuc             ###   ########.fr       */
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

	test = &gay;
	i = 0;
	i = ft_printf("%|");
	printf("\ni = %d\n", i);
	i = printf("%");
	printf("\ni = %d\n", i);
	return (0);
}
