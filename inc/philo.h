/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:52:49 by ybouryal          #+#    #+#             */
/*   Updated: 2025/02/26 11:54:51 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define FALSE 0
# define TRUE 1
# define ERROR -1
# define A 1664525
# define C 1013904223
# define M 0xFFFFFFFF

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long long		last_meal_time;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	right_fork;
	t_data			*data;
	pthread_t		thread;
}	t_philo;

struct s_data
{
	int				num_philos;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				must_eat_count;
	int				finished_philos;
	int				all_alive;
	long long		start_time;
	pthread_mutex_t	alive_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	meal_check;
	t_philo			*philos;
};

/* utils.c-------------------------------------------------------------------*/
void			ft_putendl_fd(char *str, int fd);
long			ft_atol(char *nptr);
long long		get_time(void);
void			print_status(t_philo *philo, char *status);
int				is_alive(t_data *data);
int				kill_philo(t_data *data);

/* actions.c-----------------------------------------------------------------*/
void			think(t_philo *philo);
void			eat(t_philo *philo);
void			take_forks(t_philo *philo);
void			put_forks(t_philo *philo);
void			sleep_philo(t_philo *philo);

/* routines.c----------------------------------------------------------------*/
void			*philo_routine(void *arg);
void			*monitor_routine(void *arg);

/* simulation.c--------------------------------------------------------------*/
int				init_simulation(t_data *data);
void			start_simulation(t_data *data);

/* parser.c------------------------------------------------------------------*/
int				parse_args(int ac, char **av, t_data *data);

/* cleanup.c-----------------------------------------------------------------*/
void			cleanup(t_data *data);

/* random.c------------------------------------------------------------------*/
unsigned int	ft_rand(unsigned int *seed);
unsigned int	ft_srand(void);
unsigned int	ft_rand_range(unsigned int *seed,
					unsigned int min, unsigned int max);

#endif /* PHILO_H */
