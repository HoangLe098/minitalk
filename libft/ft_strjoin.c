/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:29:12 by hoale             #+#    #+#             */
/*   Updated: 2024/11/09 11:29:57 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Malloc and join s1 s2 into a new str
char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ptr;
	unsigned int	sc;
	unsigned int	jc;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ptr = (char *)(malloc(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ptr == NULL)
		return (NULL);
	sc = 0;
	jc = 0;
	while (s1[sc])
		ptr[jc++] = s1[sc++];
	sc = 0;
	while (s2[sc])
		ptr[jc++] = s2[sc++];
	ptr[jc] = 0;
	return (ptr);
}
