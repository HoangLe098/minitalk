/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:43:40 by hoale             #+#    #+#             */
/*   Updated: 2025/01/17 15:57:44 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Return ptr from where func find char c
char	*ft_strchr(const char *s, int c)
{
	const char		*ptr;
	unsigned char	cc;

	cc = (unsigned char)c;
	ptr = s;
	while (*ptr != 0)
	{
		if (cc == *ptr)
			return ((char *)ptr);
		ptr++ ;
	}
	if (cc == 0)
		return ((char *)ptr);
	return (NULL);
}
