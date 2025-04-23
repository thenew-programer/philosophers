/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:24:04 by ybouryal          #+#    #+#             */
/*   Updated: 2025/02/27 13:41:28 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*philo_routine(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	if (philo->data->num_philos == 1)
	{
		think(philo);
		pthread_mutex_lock(&philo->right_fork);
		print_status(philo, "has taken a fork");
		while (is_alive(philo->data))
			continue ;
		pthread_mutex_unlock(&philo->right_fork);
		return (NULL);
	}
	if (philo->id % 2)
		usleep(3000);
	while (is_alive(philo->data))
	{
		think(philo);
		take_forks(philo);
		eat(philo);
		sleep_philo(philo);
	}
	return (NULL);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (is_alive(data))
	{
		if (!eat_check(data))
			return (NULL);
		usleep(500);
	}
	return (NULL);
}
