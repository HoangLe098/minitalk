/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:00:16 by hoale             #+#    #+#             */
/*   Updated: 2025/02/27 18:25:10 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char		*ptr;
	int				i;
	unsigned char	cc;

	cc = (unsigned char)c;
	ptr = s;
	i = 0;
	while (*ptr != 0)
		ptr++ ;
	if (cc == 0)
		return ((char *)ptr);
	while (ptr >= s)
	{
		if (cc == *ptr)
			return ((char *)ptr);
		ptr-- ;
	}
	return (0);
}
