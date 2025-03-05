/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:43:32 by hoale             #+#    #+#             */
/*   Updated: 2025/02/27 18:25:18 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s, size_t n)
{
	char			*ptr;
	unsigned int	i;

	if (n >= ft_strlen(s))
		n = ft_strlen(s);
	ptr = (char *)malloc(n + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s[i] && i < n)
	{
		ptr[i] = s[i];
		i++ ;
	}
	ptr[i] = 0;
	return (ptr);
}

//Trim the beginning of the string
static char	*trim_start(char const *ptr, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (*ptr == set[i])
		{
			ptr++ ;
			i = 0;
		}
		else
			i++ ;
	}
	return ((char *)ptr);
}

//Trim the end of the string
static size_t	trim_end(char const *ptr, char const *set)
{
	size_t			n;
	unsigned int	i;

	n = ft_strlen(ptr);
	i = 0;
	while (set[i])
	{
		if (ptr[n - 1] == set[i])
		{
			n--;
			i = 0;
		}
		else
			i++;
	}
	return (n);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*ptr;
	size_t		n;	

	ptr = s1;
	if (!ptr)
		return (NULL);
	ptr = trim_start(ptr, set);
	n = trim_end(ptr, set);
	return (ft_strndup(ptr, n));
}
