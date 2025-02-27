/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:56:19 by ybouryal          #+#    #+#             */
/*   Updated: 2025/02/27 11:14:46 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, char *status)
{
	long long	timestamp;

	pthread_mutex_lock(&philo->data->print_mutex);
	timestamp = get_time() - philo->data->start_time;
	if (philo->data->all_alive)
	{
		printf(BLUE"%lld "RESET, timestamp);
		printf(WHITE"%d "RESET, philo->id);
		printf("%s\n", status);
	}
	pthread_mutex_unlock(&philo->data->print_mutex);
}

int	is_alive(t_data *data)
{
	int	ret;

	pthread_mutex_lock(&data->alive_mutex);
	ret = data->all_alive;
	pthread_mutex_unlock(&data->alive_mutex);
	return (ret);
}

int	kill_philo(t_data *data)
{
	pthread_mutex_lock(&data->alive_mutex);
	data->all_alive = FALSE;
	pthread_mutex_unlock(&data->alive_mutex);
	return (TRUE);
}

int	eat_check(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philos && is_alive(data))
	{
		pthread_mutex_lock(&data->meal_check);
		if (data->must_eat_count > 0
			&& data->finished_philos == data->num_philos)
		{
			kill_philo(data);
			pthread_mutex_unlock(&data->meal_check);
			return (FALSE);
		}
		if (get_time() - data->philos[i].last_meal_time > data->time_to_die)
		{
			print_status(&data->philos[i], BOLD_RED"died"RESET);
			kill_philo(data);
			pthread_mutex_unlock(&data->meal_check);
			return (FALSE);
		}
		pthread_mutex_unlock(&data->meal_check);
	}
	return (TRUE);
}
