/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:26:28 by hoale             #+#    #+#             */
/*   Updated: 2024/11/22 14:12:43 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static unsigned int	unsigned_size_hex(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		count++ ;
	}
	return (count);
}

static unsigned int	ulong_size_hex(unsigned long n)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		count++ ;
	}
	return (count);
}

void	conv_x(va_list **args, int **count)
{
	unsigned int	n;

	n = va_arg(**args, unsigned int);
	ft_putunsigned_hex(n, 'a');
	**count += unsigned_size_hex(n);
}

void	conv_upperx(va_list **args, int **count)
{
	unsigned int	n;

	n = va_arg(**args, unsigned int);
	ft_putunsigned_hex(n, 'A');
	**count += unsigned_size_hex(n);
}

void	conv_p(va_list **args, int **count)
{
	void	*n;
	void	**m;

	n = va_arg(**args, void *);
	m = &n;
	if (!n)
	{
		write(1, "(nil)", 5);
		**count += 5;
		return ;
	}
	write(1, "0x", 2);
	ft_putulong_hex((unsigned long)*m, 'a');
	**count += ulong_size_hex((unsigned long)*m) + 2;
}
