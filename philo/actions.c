/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:33:45 by ybouryal          #+#    #+#             */
/*   Updated: 2025/02/25 11:41:55 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	think(t_philo *philo)
{
	print_status(philo, "is thinking");
}

void	eat(t_philo *philo)
{
	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->data->meal_check);
	philo->last_meal_time = get_time();
	philo->meals_eaten++;
	if (philo->meals_eaten == philo->data->must_eat_count)
		philo->data->finished_philos++;
	pthread_mutex_unlock(&philo->data->meal_check);
	usleep(philo->data->time_to_eat * 1000);
}

void	take_forks(t_philo *philo)
{
	// if (philo->id % 2 != 0)
	// {
	// 	pthread_mutex_lock(&philo->right_fork);
	// 	print_status(philo, "has taken a fork");
	// 	pthread_mutex_lock(philo->left_fork);
	// 	print_status(philo, "has taken a fork");
	// }
	// else
	// {
	// 	pthread_mutex_lock(philo->left_fork);
	// 	print_status(philo, "has taken a fork");
	// 	pthread_mutex_lock(&philo->right_fork);
	// 	print_status(philo, "has taken a fork");
	// }
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->right_fork);
	print_status(philo, "has taken a fork");
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	sleep_philo(t_philo *philo)
{
	print_status(philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
}
