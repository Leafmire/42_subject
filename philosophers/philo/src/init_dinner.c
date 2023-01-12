/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dinner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:47:53 by gson              #+#    #+#             */
/*   Updated: 2022/04/26 05:31:56 by gson             ###   ########.fr       */
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

void	init_mutex(t_dinner *dinner)
{
	pthread_mutex_init(&dinner->table.writing, NULL);
	pthread_mutex_init(&dinner->table.dead, NULL);
	pthread_mutex_init(&dinner->table.finish, NULL);
}

void	init_table(t_dinner *dinner)
{
	int	i;

	dinner->table.start_time = present_time();
	dinner->table.stop = 0;
	dinner->table.philo_finish_cnt = 0;
	i = 0;
	init_mutex(dinner);
	while (i < dinner->table.num)
	{
		dinner->philo[i].id = i + 1;
		dinner->philo[i].r_fork = NULL;
		pthread_mutex_init(&dinner->philo[i].l_fork, NULL);
		dinner->philo[i].time_eat = dinner->table.start_time;
		dinner->philo[i].num_eat = 0;
		dinner->philo[i].finish = 0;
		if (dinner->table.num == 1)
			return ;
		if (i == dinner->table.num - 1)
			dinner->philo[i].r_fork = &dinner->philo[0].l_fork;
		else
			dinner->philo[i].r_fork = &dinner->philo[i + 1].l_fork;
		i++;
	}
}
