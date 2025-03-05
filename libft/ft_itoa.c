/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:44:50 by hoale             #+#    #+#             */
/*   Updated: 2024/11/11 13:40:56 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	size(int n)
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

char	*ft_itoa(int n)
{
	char			*res;
	unsigned int	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = size(n);
	res = (char *)malloc((i + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	if (n == 0)
		res[0] = '0';
	res[i] = 0;
	while (n != 0)
	{
		i--;
		res[i] = ((n % 10) + 48);
		n /= 10;
	}
	return (res);
}
