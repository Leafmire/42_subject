/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:20:33 by gson              #+#    #+#             */
/*   Updated: 2022/03/18 14:02:08 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"

int	print_character(int pid, char c)
{
	if (c == 0)
	{
		kill(pid, SIGUSR2);
		return (1);
	}
	ft_putchar_fd(c, 1);
	kill(pid, SIGUSR1);
	return (0);
}

void	handler(int	signo, siginfo_t *info, void *context)
{
	static int				i = 0;
	static unsigned char	c = 0;
	static int				pid = 0;

	(void)context;
	pid = info->si_pid;
	if (i == 7)
	{
		if (signo == SIGUSR1)
			c |= 1;
		i = 0;
		if (print_character(pid, c) == 1)
			return ;
		c = 0;
	}
	else
	{
		if (signo == SIGUSR1)
			c |= 1;
		c <<= 1;
		i++;
	}
}

void	print_pid(pid_t pid)
{
	ft_putstr_fd("SERVER PID : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	act;

	pid = getpid();
	print_pid(pid);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = handler;
	sigaction(SIGUSR1, &act, (struct sigaction *) NULL);
	sigaction(SIGUSR2, &act, (struct sigaction *) NULL);
	while (1)
		pause();
	return (0);
}
