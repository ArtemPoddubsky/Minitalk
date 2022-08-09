#include "minitalk.h"

int	ft_bit(int pid, int byte)
{
	int	position;

	position = 0;
	while (position < 8)
	{
		if ((byte & (1 << position)) != 0)
		{
			if (kill(pid, SIGUSR1) != 0)
				return (-1);
		}
		else
			if (kill(pid, SIGUSR2) != 0)
				return (-1);
		position++;
		usleep(700);
	}
	return (0);
}

int	send_bit(int pid, char *str)
{
	int	i;
	int	ret;

	i = 0;
	while (str[i] != '\0')
	{
		ret = ft_bit(pid, str[i]);
		if (ret == 0)
			i++;
		else
			break ;
	}
	return (ret);
}

void	handles(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Signal received\n", 16);
}

void	initiate_handler(struct sigaction *action)
{
	action->sa_flags = SA_RESTART;
	action->sa_handler = handles;
	sigemptyset(&action->sa_mask);
	sigaddset(&action->sa_mask, SIGUSR1);
	sigaddset(&action->sa_mask, SIGUSR2);
	sigaction(SIGUSR1, action, 0);
	sigaction(SIGUSR2, action, 0);
}

int	main(int argc, char **argv)
{
	struct sigaction	action;
	int					ret;

	if (argc != 3 || check_pid(argv[1]) == -1)
	{
		write(1, "Wrong input", 11);
		return (-1);
	}
	action.sa_flags = SA_RESTART;
	action.sa_handler = handles;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	ret = send_bit(ft_atoi(argv[1]), argv[2]);
	return (ret);
}
