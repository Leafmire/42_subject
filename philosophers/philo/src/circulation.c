/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circulation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 02:28:01 by gson              #+#    #+#             */
/*   Updated: 2022/04/26 05:31:49 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	after_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->writing);
	write_format(philo, "is sleeping\n");
	pthread_mutex_unlock(&philo->table->writing);
	usleep_time(philo->table->time_to_sleep);
	pthread_mutex_lock(&philo->table->writing);
	write_format(philo, "is thinking\n");
	pthread_mutex_unlock(&philo->table->writing);
}

int	lock_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	pthread_mutex_lock(&philo->table->writing);
	write_format(philo, "has taken a fork\n");
	pthread_mutex_unlock(&philo->table->writing);
	if (philo->table->num == 1)
	{
		usleep_time(philo->table->time_to_die * 2);
		return (-1);
	}
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(&philo->table->writing);
	write_format(philo, "has taken a fork\n");
	pthread_mutex_unlock(&philo->table->writing);
	return (0);
}

void	circulation(t_philo *philo)
{
	if (lock_fork(philo) == -1)
		return ;
	pthread_mutex_lock(&philo->table->writing);
	write_format(philo, "is eating\n");
	philo->time_eat = present_time();
	pthread_mutex_unlock(&philo->table->writing);
	usleep_time(philo->table->time_to_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(&philo->l_fork);
	if (++philo->num_eat == philo->table->must_eat)
	{
		pthread_mutex_lock(&philo->table->finish);
		philo->finish = 1;
		philo->table->philo_finish_cnt++;
		pthread_mutex_unlock(&philo->table->finish);
	}
	after_eating(philo);
}
