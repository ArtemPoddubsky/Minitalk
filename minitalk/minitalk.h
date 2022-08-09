#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include "libft/libft.h"

void	ft_action(int signal, siginfo_t *siginfo, void *context);

int		ft_putchar(char c);
int		check_pid(char *str);
int		get_pid(char *str);

int		ft_bit(int pid, int byte);
int		send_bit(int pid, char *str);
void	handles(int sig);
void	initiate_handler(struct sigaction *action);

#endif