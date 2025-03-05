/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_dec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:40:55 by hoale             #+#    #+#             */
/*   Updated: 2024/11/22 13:22:36 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static unsigned int	size_dec(int n)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		count++ ;
	}
	while (n != 0)
	{
		n /= 10;
		count++ ;
	}
	return (count);
}

static unsigned int	unsigned_size(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++ ;
	}
	return (count);
}

void	conv_di(va_list **args, int **count)
{
	int	n;

	n = va_arg(**args, int);
	ft_putnbr_fd(n, 1);
	if (n == -2147483648)
	{
		**count += 11;
		return ;
	}
	else
		**count += size_dec(n);
}

void	conv_u(va_list **args, int **count)
{
	unsigned int	n;

	n = va_arg(**args, unsigned int);
	ft_putunsigned(n);
	**count += unsigned_size(n);
}
