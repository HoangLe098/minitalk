/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:55:21 by hoale             #+#    #+#             */
/*   Updated: 2025/01/17 15:56:46 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	cc;

	cc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = cc;
		i++ ;
	}
	return (s);
}
