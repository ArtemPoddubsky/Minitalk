#include "minitalk.h"

void	ft_action(int signal, siginfo_t *siginfo, void *context)
{
	static int	byte = 0;
	static int	count = 0;

	(void)context;
	if (signal == SIGUSR1)
		byte |= (1 << count);
	count++;
	if (count == 8)
	{
		if (byte != 0)
		{
			kill(siginfo->si_pid, SIGUSR1);
			ft_putchar(byte);
			byte = 0;
			count = 0;
		}
	}
}

int	main(void)
{
	struct sigaction	action;
	int					i;

	action.sa_flags = SA_RESTART;
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = ft_action;
	sigemptyset(&action.sa_mask);
	i = getpid();
	write(1, "My PID is ", 10);
	ft_putnbr_fd(i, 1);
	write(1, "\nWaiting...\n", 12);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
