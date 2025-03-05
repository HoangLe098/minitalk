
#include "minitalk.h"

void	signal_action(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x01 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++ ;
		usleep(500);
	}
}

int	main(int ac, char ** av)
{
	pid_t	pid;
	int		i;

	i = 0;
	if (ac == 3)
	{
		pid = atoi(av[1]);
		while (av[2][i])
		{
			signal_action(pid, av[2][i]);
			i++ ;
		}
		signal_action(pid, '\n');
	}
	else
		return(printf("Wrong arguments\n"), EXIT_FAILURE);
	return(EXIT_SUCCESS);
}
