/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:52:19 by ybouryal          #+#    #+#             */
/*   Updated: 2025/02/27 11:31:11 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_args(int ac, char **av);
static int	check_data(t_data *data);

int	parse_args(int ac, char **av, t_data *data)
{
	if (ac != 5 && ac != 6)
		return (ft_putendl_fd(RED"Usage: ./philo <nbr-philo> <time_to_die>"\
			"<time_to_eat> <time_to_sleep> [meals_required]"RESET, 2), FALSE);
	if (!check_args(ac, av))
		return (FALSE);
	data->num_philos = ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]);
	data->time_to_eat = ft_atol(av[3]);
	data->time_to_sleep = ft_atol(av[4]);
	data->must_eat_count = -1;
	if (ac == 6)
		data->must_eat_count = ft_atol(av[5]);
	data->all_alive = TRUE;
	data->finished_philos = 0;
	if (!check_data(data))
		return (FALSE);
	return (TRUE);
}

static int	is_nbr_valid(char *nbr)
{
	int	i;

	i = 0;
	while (nbr[i])
	{
		if (!ft_isdigit((char)nbr[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static void	parsing_err(int id)
{
	if (id == 1)
		ft_putendl_fd(RED"invalid number of philos."RESET, 2);
	else if (id == 2)
		ft_putendl_fd(RED"invalid time to die."RESET, 2);
	else if (id == 3)
		ft_putendl_fd(RED"invalid time to eat."RESET, 2);
	else if (id == 4)
		ft_putendl_fd(RED"invalid time to sleep."RESET, 2);
	else if (id == 5)
		ft_putendl_fd(RED"invalid number of times to eat before die."RESET, 2);
}

static int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_nbr_valid(av[i]))
		{
			parsing_err(i);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

static int	check_data(t_data *data)
{
	if (data->must_eat_count == 0)
		return (FALSE);
	if (data->time_to_die == 0)
		return (FALSE);
	if (data->num_philos <= 0)
		return (FALSE);
	if (data->num_philos > 200)
	{
		ft_putendl_fd(RED"numbers of philos exceeded the limit."RESET, 2);
		return (FALSE);
	}
	return (TRUE);
}
