/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:52:19 by ybouryal          #+#    #+#             */
/*   Updated: 2025/02/25 11:03:30 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	parse_args(int ac, char **av, t_data *data)
{
	if (ac != 5 && ac != 6)
		return (ft_putendl_fd("Usage: ./philo <nbr-philo> <time_to_die>"\
		  "<time_to_eat> <time_to_sleep> [meals_required]", 2), ERROR);
	data->num_philos = ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]);
	data->time_to_eat = ft_atol(av[3]);
	data->time_to_sleep = ft_atol(av[4]);
	if (av[5] != NULL)
		data->must_eat_count = ft_atol(av[5]);
	else
		data->must_eat_count = -1;
	data->all_alive = TRUE;
	data->finished_philos = 0;

	return (TRUE);
}
