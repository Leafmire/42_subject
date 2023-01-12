/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dinner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:47:53 by gson              #+#    #+#             */
/*   Updated: 2022/04/26 05:35:13 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	check_args(int argc, char **argv, t_dinner *dinner)
{
	if (argc == 5 || argc == 6)
	{
		if (check_numeric(argc, argv) != 0)
			return (-1);
		dinner->table.num = ft_atoi(argv[1]);
		dinner->table.time_to_die = ft_atoi(argv[2]);
		dinner->table.time_to_eat = ft_atoi(argv[3]);
		dinner->table.time_to_sleep = ft_atoi(argv[4]);
		dinner->table.must_eat = -INF;
		if (argc == 6)
			dinner->table.must_eat = ft_atoi(argv[5]);
		if (dinner->table.num <= 0 || dinner->table.time_to_die <= 0 \
			|| dinner->table.time_to_eat <= 0 || \
			dinner->table.time_to_sleep <= 0)
			return (-1);
		return (0);
	}
	else
		return (-1);
}

sem_t	*relink_semaphore(char *name, int value)
{
	sem_open(name, O_CREAT | O_EXCL, 0644, value);
	sem_unlink(name);
	return (sem_open(name, O_CREAT | O_EXCL, 0644, value));
}

void	open_semaphore(t_dinner *dinner)
{
	dinner->table.dead = relink_semaphore("dead", 1);
	dinner->table.writing = relink_semaphore("writing", 1);
	dinner->table.finish = relink_semaphore("finish", 0);
	dinner->table.philo_finish_cnt = relink_semaphore("philo_finish_cnt", 0);
}

void	init_table(t_dinner *dinner)
{
	int	i;

	dinner->table.start_time = present_time();
	dinner->table.stop = 0;
	dinner->table.forks = relink_semaphore("forks", dinner->table.num);
	open_semaphore(dinner);
	i = 0;
	while (i < dinner->table.num)
	{
		dinner->philo[i].id = i + 1;
		dinner->philo[i].time_eat = dinner->table.start_time;
		dinner->philo[i].num_eat = 0;
		dinner->philo[i].finish = 0;
		if (dinner->table.num == 1)
			return ;
		i++;
	}
}
