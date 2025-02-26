/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:24:04 by ybouryal          #+#    #+#             */
/*   Updated: 2025/02/26 11:55:20 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*philo_routine(void *arg)
{
	t_philo			*philo;
	unsigned int	seed;

	philo = (t_philo *)arg;
	if (philo->data->num_philos == 1)
	{
		think(philo);
		pthread_mutex_lock(&philo->right_fork);
		print_status(philo, "has taken a fork");
		while (is_alive(philo->data))
			usleep(100);
		pthread_mutex_unlock(&philo->right_fork);
		return (NULL);
	}
	seed = ft_srand();
    usleep(ft_rand_range(&seed, 0, 1000));
	// if (philo->id % 2 != 0)
	// 	usleep(1000);
	while (is_alive(philo->data))
	{
		think(philo);
		take_forks(philo);
		eat(philo);
		put_forks(philo);
		sleep_philo(philo);
	}
	return (NULL);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (is_alive(data))
	{
		i = -1;
		while (++i < data->num_philos && is_alive(data))
		{
			pthread_mutex_lock(&data->meal_check);
			if (data->must_eat_count > 0 && data->finished_philos == data->num_philos)
			{
				kill_philo(data);
				pthread_mutex_unlock(&data->meal_check);
				return (NULL);
			}
			if (get_time() - data->philos[i].last_meal_time > data->time_to_die)
			{
				print_status(&data->philos[i], "died");
				kill_philo(data);
				pthread_mutex_unlock(&data->meal_check);
				return (NULL);
			}
			pthread_mutex_unlock(&data->meal_check);
		}
		usleep(1000);
	}
	return (NULL);
}
