/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:34:19 by hoale             #+#    #+#             */
/*   Updated: 2024/11/22 14:05:26 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putunsigned(unsigned int n)
{
	char	d;

	if (n >= 10)
		ft_putunsigned(n / 10);
	d = (n % 10) + '0';
	write(1, &d, 1);
}

void	ft_putunsigned_hex(unsigned int n, char start)
{
	char	d;

	if (n >= 16)
		ft_putunsigned_hex(n / 16, start);
	d = n % 16;
	if (d >= 0 && d <= 9)
		d += '0';
	else
		d = d - 10 + start;
	write(1, &d, 1);
}

void	ft_putulong_hex(unsigned long n, char start)
{
	char	d;

	if (n >= 16)
		ft_putulong_hex(n / 16, start);
	d = n % 16;
	if (d >= 0 && d <= 9)
		d += '0';
	else
		d = d - 10 + start;
	write(1, &d, 1);
}
