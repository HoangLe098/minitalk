/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoale <hoale@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:17:58 by hoale             #+#    #+#             */
/*   Updated: 2025/03/15 18:00:34 by hoale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_msg_received = 0;

static void	handle_server_signal(int sig, siginfo_t *info, void *context)
{
	static int		bit = 0;
	static pid_t	server_pid;

	(void)context;
	if (info->si_pid != 0)
		server_pid = info->si_pid;
	if (sig == SIGUSR2)
	{
		bit++ ;
		g_msg_received = 1;
	}
	else if (sig == SIGUSR1)
	{
		g_msg_received = 1;
		usleep(400);
		ft_printf("Server (%d) received %d bytes", server_pid, bit / 8);
		exit(EXIT_SUCCESS);
	}
}

void	send_char(pid_t pid, char c)
{
	int	bit;
	int	i;

	i = 7;
	while (i >= 0)
	{
		bit = (c & (1 << i));
		if (bit != 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (g_msg_received == 0)
			pause();
		g_msg_received = 0;
		i-- ;
	}
}

static void	send_msg(int pid, char *msg)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(msg))
	{
		send_char(pid, msg[i]);
		i++ ;
	}
	send_char(pid, '\0');
}

static int	is_valid_pid(char *pid)
{
	int	i;

	i = 0;
	if (pid[i] == '\0')
		return (0);
	while (pid[i])
	{
		if (pid[i] > '9' || pid[i] < '0')
			return (0);
		i++ ;
	}
	if (ft_atoi(pid) <= 0)
		return (0);
	if (kill(ft_atoi(pid), 0) == -1)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	pid_t				pid;
	char				*msg;
	int					i;
	struct sigaction	sa;

	i = 0;
	if (ac == 3 && is_valid_pid(av[1]))
	{
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = handle_server_signal;
		sigemptyset(&sa.sa_mask);
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pid = ft_atoi(av[1]);
		msg = av[2];
		send_msg(pid, msg);
	}
	else
		return (ft_printf("Wrong arguments\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
