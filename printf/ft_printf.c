/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:46:01 by hoale             #+#    #+#             */
/*   Updated: 2024/11/22 14:54:51 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *input, ...)
{
	va_list	args;
	char	*ptr;
	int		count;

	va_start(args, input);
	if (!input)
		return (-1);
	ptr = (char *)input;
	count = 0;
	while (*ptr != 0)
	{
		if (*ptr != '%')
		{
			ft_putchar_fd(*ptr, 1);
			ptr++ ;
			count++ ;
		}
		else
			conversion(&ptr, &args, &count);
	}
	va_end(args);
	return (count);
}

void	conversion(char **ptr, va_list *args, int *count)
{
	if (*(*ptr + 1) == 'c')
		conv_c(&args, &count);
	else if (*(*ptr + 1) == 's')
		conv_s(&args, &count);
	else if (*(*ptr + 1) == 'd' || *(*ptr + 1) == 'i')
		conv_di(&args, &count);
	else if (*(*ptr + 1) == '%')
		conv_percent(&count);
	else if (*(*ptr + 1) == 'u')
		conv_u(&args, &count);
	else if (*(*ptr + 1) == 'x')
		conv_x(&args, &count);
	else if (*(*ptr + 1) == 'X')
		conv_upperx(&args, &count);
	else if (*(*ptr + 1) == 'p')
		conv_p(&args, &count);
	else
	{
		write(1, "%", 1);
		*ptr += 1;
		*count += 1;
		return ;
	}
	*ptr += 2;
	return ;
}
