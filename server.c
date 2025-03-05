
#include "minitalk.h"

void	signal_handler(int signal)
{
	static int	bit = 0;
	static int	c = 0;

	if (signal == SIGUSR1)
		c |= (0x01 << bit);
	bit++ ;
	if (bit == 8)
	{
		ft_printf("%c", c);
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
	while (1)
		pause();
	return (EXIT_SUCCESS);
}