/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:18:27 by hoale             #+#    #+#             */
/*   Updated: 2025/03/13 13:21:08 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_received_msg[2000000];

static int	end_of_msg(pid_t client_pid, int char_index)
{
	ft_printf("%s\n", g_received_msg);
	ft_bzero(g_received_msg, 2000000);
	kill(client_pid, SIGUSR1);
	return (char_index = 0);
}

static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int		bit = 0;
	static char		c = 0;
	static int		i = 0;
	static pid_t	client_pid;

	(void)context;
	c <<= 1;
	if (info->si_pid != 0)
		client_pid = info->si_pid;
	if (signal == SIGUSR2)
		c |= 1;
	if (signal == SIGUSR1 || signal == SIGUSR2)
		kill(client_pid, SIGUSR2);
	bit++ ;
	if (bit == 8)
	{
		if (c == '\0')
			i = end_of_msg(client_pid, i);
		else
			g_received_msg[i++] = c;
		bit = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	int					pid_id;
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
		return (ft_printf("Wrong arguments!\n"), EXIT_FAILURE);
	pid_id = getpid();
	ft_printf("Server ID: %d\n", pid_id);
	ft_printf("Waiting for the sinal...\n");
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_bzero(g_received_msg, 2000000);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
