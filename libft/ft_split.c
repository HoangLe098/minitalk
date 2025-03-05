/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:09:20 by hoale             #+#    #+#             */
/*   Updated: 2025/02/20 16:22:18 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	word_count(char const *s, char c)
{
	unsigned int	count;
	unsigned int	i;
	char			prev;

	count = 0;
	i = 0;
	prev = c;
	while (s[i])
	{
		if (s[i] != c && prev == c)
			count++ ;
		prev = s[i];
		i++ ;
	}
	return (count);
}

static char	*fill_word(char const *ptr, char c)
{
	unsigned int	n;
	unsigned int	i;
	char			*word;

	n = 0;
	while (ptr[n] != c && ptr[n] != 0)
		n++ ;
	word = (char *)malloc((n + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (ptr[i] && i < n)
	{
		word[i] = ptr[i];
		i++ ;
	}
	word[i] = 0;
	return (word);
}

static void	free_all(char **result, unsigned int count)
{
	while (0 < count)
		free(result[--count]);
	free(result);
}

static void	set_zero(unsigned int *count, unsigned int *i)
{
	*count = 0;
	*i = 0;
}

char	**ft_split(char const *s, char c)
{
	char			**result;
	char			*word;
	unsigned int	count;
	unsigned int	i;

	result = (char **)malloc((word_count(s, c) + 1) * (sizeof(char *)));
	if ((!result) || (!s))
		return (NULL);
	set_zero(&count, &i);
	while (count < word_count(s, c))
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			word = fill_word(s + i, c);
			if (!word)
			{
				free_all(result, count);
				return (NULL);
			}
			result[count++] = word;
		}
		i++ ;
	}
	result[count] = NULL;
	return (result);
}
