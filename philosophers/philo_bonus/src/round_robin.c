/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_robin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:07:31 by gson              #+#    #+#             */
/*   Updated: 2022/04/26 05:41:44 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/philosophers.h"

void	*make_dead(void	*arg)
{
	t_philo					*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->table->dead);
		if (!philo->finish && \
			(present_time() - philo->time_eat) >= \
			(long)(philo->table->time_to_die))
		{
			sem_wait(philo->table->writing);
			write_format(philo, "died\n");
			sem_post(philo->table->writing);
			sem_post(philo->table->finish);
			usleep_time(10);
			sem_post(philo->table->dead);
			break ;
		}
		sem_post(philo->table->dead);
	}
	return (NULL);
}

void	setup(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep_time(100);
	pthread_create(&philo->death, NULL, make_dead, philo);
	pthread_detach(philo->death);
	while (1)
	{
		circulation(philo);
	}
	exit(0);
}

void	round_robin(t_dinner *dinner)
{
	int	i;

	i = 0;
	while (i < dinner->table.num)
	{
		dinner->philo[i].table = &dinner->table;
		dinner->philo[i].pid = fork();
		if (dinner->philo[i].pid == 0)
			setup(&dinner->philo[i]);
		else if (dinner->philo[i].pid < 0)
		{
			ft_error("fork Failed.\n");
			exit(1);
		}
		i++;
	}
}
