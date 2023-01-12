/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 01:26:05 by gson              #+#    #+#             */
/*   Updated: 2022/03/26 01:26:05 by gson             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include "../include/philosophers.h"

void	*check_must_eat(void *arg)
{
	int			i;
	t_dinner	*dinner;

	dinner = arg;
	i = 0;
	while (i < dinner->table.num)
	{
		sem_wait(dinner->table.philo_finish_cnt);
		i++;
	}
	sem_post(dinner->table.finish);
	return (NULL);
}

void	*quit_process(void *arg)
{
	int			i;
	t_dinner	*dinner;

	dinner = arg;
	sem_wait(dinner->table.finish);
	i = 0;
	while (i < dinner->table.num)
	{
		kill(dinner->philo[i].pid, SIGTERM);
		i++;
	}
	return (NULL);
}

void	destroy_semaphore(t_dinner	*dinner)
{
	int	i;
	int	status;

	i = 0;
	while (i < dinner->table.num)
	{
		waitpid(dinner->philo->pid, &status, 0);
		i++;
	}
	sem_close(dinner->table.writing);
	sem_close(dinner->table.forks);
	sem_close(dinner->table.dead);
	sem_close(dinner->table.finish);
	sem_close(dinner->table.philo_finish_cnt);
	sem_unlink("writing");
	sem_unlink("forks");
	sem_unlink("dead");
	sem_unlink("finish");
	sem_unlink("philo_finish_cnt");
	free(dinner->philo);
}

int	main(int argc, char **argv)
{
	t_dinner	dinner;
	pthread_t	must_eat_thread;
	pthread_t	quit_thread;

	if (check_args(argc, argv, &dinner) != 0)
		return (ft_error("Invalid argument.\n"));
	dinner.philo = malloc(sizeof(t_philo) * dinner.table.num);
	if (!dinner.philo)
		return (ft_error("malloc error.\n"));
	init_table(&dinner);
	round_robin(&dinner);
	if (dinner.table.must_eat > 0)
	{
		pthread_create(&must_eat_thread, NULL, check_must_eat, &dinner);
		pthread_detach(must_eat_thread);
	}
	pthread_create(&quit_thread, NULL, quit_process, &dinner);
	pthread_detach(quit_thread);
	destroy_semaphore(&dinner);
}
