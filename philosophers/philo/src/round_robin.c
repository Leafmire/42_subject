/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_robin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:07:31 by gson              #+#    #+#             */
/*   Updated: 2022/04/26 05:32:59 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	dead_or_alive(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->dead);
	if (philo->table->stop == 1)
	{
		pthread_mutex_unlock(&philo->table->dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->dead);
	return (0);
}

void	make_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->finish);
	if (!dead_or_alive(philo) && \
	!philo->finish && (present_time() - philo->time_eat) >= \
	(long)(philo->table->time_to_die))
	{
		pthread_mutex_unlock(&philo->table->finish);
		pthread_mutex_lock(&philo->table->writing);
		write_format(philo, "died\n");
		pthread_mutex_unlock(&philo->table->writing);
		pthread_mutex_lock(&philo->table->dead);
		philo->table->stop = 1;
		pthread_mutex_unlock(&philo->table->dead);
		return ;
	}
	pthread_mutex_unlock(&philo->table->finish);
}

void	*monitor(void	*arg)
{
	t_dinner	*dinner;
	int			i;

	dinner = arg;
	while (1)
	{
		i = 0;
		while (i < dinner->table.num)
		{
			make_dead(&dinner->philo[i]);
			i++;
		}
		if (dinner->table.philo_finish_cnt == dinner->table.num)
		{
			pthread_mutex_lock(&dinner->table.dead);
			dinner->table.stop = 1;
			pthread_mutex_unlock(&dinner->table.dead);
		}
		if (dinner->table.stop == 1)
			break ;
	}
	return (NULL);
}

void	*setup(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep_time(100);
	while (!dead_or_alive(philo))
	{
		circulation(philo);
	}
	return (NULL);
}

void	round_robin(t_dinner *dinner)
{
	int	i;

	i = 0;
	while (i < dinner->table.num)
	{
		dinner->philo[i].table = &dinner->table;
		pthread_create(&dinner->philo[i].t_id, NULL, setup, &dinner->philo[i]);
		i++;
	}
	pthread_create(&dinner->table.dead_thread, NULL, monitor, dinner);
	pthread_detach(dinner->table.dead_thread);
}
