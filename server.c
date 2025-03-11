
#include "minitalk.h"

char	g_received_msg[2000000];

static int	end_of_msg(pid_t client_pid, int char_index)
{
	ft_printf("Received message:\n%s\n", g_received_msg);
	ft_bzero(g_received_msg, 2000000);
	kill(client_pid, SIGUSR1);
	return (char_index = 0);
}

static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static char	c = 0;
	static int	i = 0;
	static pid_t	client_pid;

	(void)context;
	c <<= 1;
	if (info->si_pid != 0)
		client_pid = info->si_pid;
	if (signal == SIGUSR2)
		c |= 1;
	if (signal == SIGUSR2 || signal == SIGUSR2)
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
	int	pid_id;

	(void)av;
	if (ac != 1)
		return(ft_printf("Wrong arguments!\n"), EXIT_FAILURE);
	pid_id = getpid();
	ft_printf("Server ID: %d\n", pid_id);
	ft_printf("Waiting for the sinal...\n");
	if (signal(SIGUSR1, signal_handler) == SIG_ERR)
		return(ft_printf("Error SIGUSR1 signal handler"), 1);
	if (signal(SIGUSR2, signal_handler) == SIG_ERR)
		return(ft_printf("Error SIGUSR2 signal handler"), 1);
	ft_bzero(g_received_msg, 2000000);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}