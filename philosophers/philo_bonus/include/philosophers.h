/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 03:39:25 by gson              #+#    #+#             */
/*   Updated: 2022/04/26 05:35:22 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/time.h>
# include <signal.h>

# define INF 2147483647

typedef struct s_table {
	int				num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	long			start_time;
	int				stop;
	sem_t			*writing;
	sem_t			*forks;
	sem_t			*dead;
	sem_t			*finish;
	sem_t			*philo_finish_cnt;
}	t_table;

typedef struct s_philo {
	int				id;
	pid_t			pid;
	pthread_t		death;
	t_table			*table;
	long			time_eat;
	int				num_eat;
	int				finish;
}	t_philo;

typedef struct s_dinner
{
	t_philo					*philo;
	t_table					table;
}	t_dinner;

size_t		ft_strlen(const char *s);
void		ft_putstr_fd(char *s, int fd);
int			ft_isdigit(int c);
int			ft_error(char *error);
int			check_numeric(int argc, char **argv);
int			ft_atoi(const char *str);
int			check_args(int argc, char **argv, t_dinner *dinner);
void		init_table(t_dinner *dinner);
long		present_time(void);
void		round_robin(t_dinner *dinner);
void		write_format(t_philo *philo, char *str);
void		circulation(t_philo *philo);
void		usleep_time(long sleep_time);

#endif
