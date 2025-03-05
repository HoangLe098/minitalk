
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
		printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid_id;

	(void)av;
	if (ac != 1)
		return(printf("Wrong arguments!\n"), EXIT_FAILURE);
	pid_id = getpid();
	printf("Server ID: %d\n", pid_id);
	printf("Waiting for the sinal...\n");
	while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
	return (EXIT_SUCCESS);
}