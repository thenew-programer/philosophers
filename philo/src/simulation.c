/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:06:44 by ybouryal          #+#    #+#             */
/*   Updated: 2025/02/25 11:23:41 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	init_simulation(t_data *data)
{
	int	i;

	data->philos = (t_philo *)malloc(sizeof (t_philo) * data->num_philos);
	if (!data->philos)
		return (ft_putendl_fd("Memory allocation Failed", 2), FALSE);
	pthread_mutex_init(&data->alive_mutex, NULL);
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->meal_check, NULL);
	i = 0;
	while (i < data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal_time = get_time();
		pthread_mutex_init(&data->philos[i].right_fork, NULL);
		data->philos[i].left_fork = &data->philos[(i + 1)
			% data->num_philos].right_fork;
		data->philos[i].data = data;
		i++;
	}
	return (TRUE);
}

void	start_simulation(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;

	data->start_time = get_time() + (data->num_philos * 2 + 10);
	i = -1;
	while (++i < data->num_philos)
		pthread_create(&data->philos[i].thread, NULL, philo_routine,
			&data->philos[i]);
	pthread_create(&monitor_thread, NULL, monitor_routine, data);
	i = -1;
	while (++i < data->num_philos)
		pthread_join(data->philos[i].thread, NULL);
	pthread_detach(monitor_thread);
}
