/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:35:20 by gson              #+#    #+#             */
/*   Updated: 2022/03/18 14:50:26 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"

void	handler(int	signo)
{
	static int	cnt;

	if (signo == SIGUSR1)
		cnt++;
	else if (signo == SIGUSR2)
	{
		ft_putstr_fd("Total receive: ", 1);
		ft_putnbr_fd(cnt, 1);
		ft_putstr_fd("byte\n", 1);
		exit(0);
	}
}

void	send_end(int pid, int i)
{
	int	end_cnt;

	end_cnt = 8;
	ft_putstr_fd("Total send: ", 1);
	ft_putnbr_fd(i, 1);
	ft_putstr_fd("byte\n", 1);
	while (end_cnt--)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

void	error_pid(void)
{
	ft_putstr_fd("Incorrect PID\n", 1);
	exit(0);
}

void	talk_server(int	pid, char **argv)
{
	int	j;
	int	i;

	i = 0;
	while (argv[2][i] != '\0')
	{
		j = 8;
		while (j--)
		{
			if ((argv[2][i] >> j & 1) == 1)
			{
				if (kill(pid, SIGUSR1) == -1)
					error_pid();
			}
			else if ((argv[2][i] >> j & 1) == 0)
			{
				if (kill(pid, SIGUSR2) == -1)
					error_pid();
			}
			usleep(100);
		}
		i++;
	}
	send_end(pid, i);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	act;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	act.sa_flags = 0;
	act.sa_handler = handler;
	sigaction(SIGUSR1, &act, (struct sigaction *) NULL);
	sigaction(SIGUSR2, &act, (struct sigaction *) NULL);
	talk_server(pid, argv);
	while (1)
		pause();
	return (0);
}
