/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:28:56 by hoale             #+#    #+#             */
/*   Updated: 2024/11/22 13:58:53 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	conv_c(va_list **args, int **count)
{
	ft_putchar_fd(va_arg(**args, int), 1);
	**count += 1;
}

void	conv_percent(int **count)
{
	ft_putchar_fd('%', 1);
	**count += 1;
}

void	conv_s(va_list **args, int **count)
{
	char	*str;

	str = va_arg(**args, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		**count += 6;
		return ;
	}
	ft_putstr_fd(str, 1);
	**count += ft_strlen(str);
}
