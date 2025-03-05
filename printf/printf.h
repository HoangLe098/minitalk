/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:29:46 by hoale             #+#    #+#             */
/*   Updated: 2025/01/17 15:10:17 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

// # include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

void	conv_c(va_list **args, int **count);
void	conv_percent(int **count);
void	conv_s(va_list **args, int **count);
void	conv_di(va_list **args, int **count);
void	conv_u(va_list **args, int **count);
void	conv_x(va_list **args, int **count);
void	conv_upperx(va_list **args, int **count);
void	conv_p(va_list **args, int **count);
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putunsigned(unsigned int n);
void	ft_putunsigned_hex(unsigned int n, char start);
void	ft_putulong_hex(unsigned long n, char start);
void	conversion(char **ptr, va_list *args, int *count);
int		ft_printf(const char *input, ...);

#endif