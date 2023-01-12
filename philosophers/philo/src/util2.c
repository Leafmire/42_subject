/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:43:34 by gson              #+#    #+#             */
/*   Updated: 2022/04/25 22:10:07 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/philosophers.h"

void	write_format(t_philo *philo, char *str)
{
	long	time;

	time = present_time() - philo->table->start_time;
	if (!dead_or_alive(philo))
		printf("%ld %d %s", time, philo->id, str);
}

long	present_time(void)
{
	struct timeval	current;

	gettimeofday(&current, 0);
	return ((current.tv_sec * 1000) + (current.tv_usec / 1000));
}

void	usleep_time(long sleep_time)
{
	long	time_start;

	time_start = present_time();
	while ((present_time() - time_start) < sleep_time)
		usleep(100);
}
