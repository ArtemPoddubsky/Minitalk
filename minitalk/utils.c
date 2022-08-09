#include "minitalk.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int	check_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (-1);
	}
	return (0);
}

int	get_pid(char *str)
{
	int	pid;

	pid = ft_atoi(str);
	while (*str)
	{
		if (ft_isdigit(*str))
			str++;
		else
			return (-1);
	}
	return (pid);
}
