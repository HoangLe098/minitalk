
#include "minitalk.h"

static volatile int	g_msg_received = 0;

static void	handle_server_signal(int sig, siginfo_t *info, void *context)
{
	static int	bit = 0;
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
		ft_printf("Server (PID: %d) received %d bytes", server_pid, bit / 8);
		ft_printf("(%d bits) and printed the full msg.\n", bit);
		exit(EXIT_SUCCESS);
	}
}

void	send_char(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x01 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_msg_received == 0)
			pause();
		g_msg_received = 0;
		bit++ ;
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
	while (g_msg_received == 0)
		pause();
}

int	main(int ac, char ** av)
{
	pid_t	pid;
	char	*msg;
	int		i;

	i = 0;
	if (ac == 3)
	{
		signal(SIGUSR1, handle_server_signal);
		signal(SIGUSR2, handle_server_signal);
		pid = ft_atoi(av[1]);
		msg = av[2];
		send_msg(pid, msg);
	}
	else
		return(ft_printf("Wrong arguments\n"), EXIT_FAILURE);
	return(EXIT_SUCCESS);
}
