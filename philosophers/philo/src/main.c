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

#include "../include/philosophers.h"

void	destroy_thread(t_dinner	*dinner)
{
	int	i;

	i = 0;
	while (i < dinner->table.num)
	{
		pthread_join(dinner->philo[i].t_id, NULL);
		i++;
	}
	pthread_mutex_destroy(&dinner->table.writing);
	pthread_mutex_destroy(&dinner->table.dead);
	pthread_mutex_destroy(&dinner->table.finish);
	i = 0;
	while (i < dinner->table.num)
	{
		pthread_mutex_destroy(&dinner->philo[i].l_fork);
		i++;
	}
	free(dinner->philo);
}

int	main(int argc, char **argv)
{
	t_dinner	dinner;

	if (check_args(argc, argv, &dinner) != 0)
		return (ft_error("Invalid argument.\n"));
	dinner.philo = malloc(sizeof(t_philo) * dinner.table.num);
	if (!dinner.philo)
		return (ft_error("malloc error.\n"));
	init_table(&dinner);
	round_robin(&dinner);
	destroy_thread(&dinner);
}
