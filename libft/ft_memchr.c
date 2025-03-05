/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:22:00 by hoale             #+#    #+#             */
/*   Updated: 2025/02/27 18:24:09 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	cc;

	cc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == cc)
			return ((void *)(s + i));
		i++ ;
	}
	return (0);
}
