/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circulation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 02:28:01 by gson              #+#    #+#             */
/*   Updated: 2022/04/26 05:36:32 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	after_eating(t_philo *philo)
{
	sem_wait(philo->table->writing);
	write_format(philo, "is sleeping\n");
	sem_post(philo->table->writing);
	usleep_time(philo->table->time_to_sleep);
	sem_wait(philo->table->writing);
	write_format(philo, "is thinking\n");
	sem_post(philo->table->writing);
}

void	circulation(t_philo *philo)
{
	sem_wait(philo->table->forks);
	sem_wait(philo->table->writing);
	write_format(philo, "has taken a fork\n");
	sem_post(philo->table->writing);
	sem_wait(philo->table->forks);
	sem_wait(philo->table->writing);
	write_format(philo, "has taken a fork\n");
	sem_post(philo->table->writing);
	sem_wait(philo->table->writing);
	write_format(philo, "is eating\n");
	philo->time_eat = present_time();
	sem_post(philo->table->writing);
	if (++philo->num_eat == philo->table->must_eat)
	{
		philo->finish = 1;
		sem_post(philo->table->philo_finish_cnt);
	}
	usleep_time(philo->table->time_to_eat);
	sem_post(philo->table->forks);
	sem_post(philo->table->forks);
	after_eating(philo);
}
