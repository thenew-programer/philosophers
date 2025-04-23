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

#include "philo.h"

void	think(t_philo *philo)
{
	print_status(philo, YELLOW"is thinking"RESET);
}

void	eat(t_philo *philo)
{
	print_status(philo, GREEN"is eating"RESET);
	pthread_mutex_lock(&philo->data->meal_check);
	if (philo->meals_eaten == philo->data->must_eat_count)
	{
		pthread_mutex_unlock(&philo->data->meal_check);
		put_forks(philo);
		return ;
	}
	philo->last_meal_time = get_time();
	philo->meals_eaten++;
	if (philo->meals_eaten == philo->data->must_eat_count)
		philo->data->finished_philos++;
	pthread_mutex_unlock(&philo->data->meal_check);
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_lock(&philo->data->meal_check);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->data->meal_check);
	put_forks(philo);
}

void	take_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(&philo->right_fork);
		print_status(philo, MAGENTA"has taken a fork"RESET);
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, MAGENTA"has taken a fork"RESET);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, MAGENTA"has taken a fork"RESET);
		pthread_mutex_lock(&philo->right_fork);
		print_status(philo, MAGENTA"has taken a fork"RESET);
	}
}

void	put_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_unlock(&philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(&philo->right_fork);
	}
}

void	sleep_philo(t_philo *philo)
{
	print_status(philo, CYAN"is sleeping"RESET);
	usleep(philo->data->time_to_sleep * 1000);
}
