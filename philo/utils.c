/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:56:19 by ybouryal          #+#    #+#             */
/*   Updated: 2025/02/25 11:39:49 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <pthread.h>

void	ft_putendl_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		write(fd, str + i, 1);
		i++;
	}
	write(fd, "\n", 1);
}

static int	ft_isspace(int c)
{
	if (c == '\n' || c == '\v' || c == '\t'
		|| c == ' ' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

long	ft_atol(char *nptr)
{
	long	result;
	long	i;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

long long	get_time(void)
{
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000LL + tv.tv_usec / 1000);
}

void	print_status(t_philo *philo, char *status)
{
	long long	timestamp;

	pthread_mutex_lock(&philo->data->print_mutex);
	timestamp = get_time() - philo->data->start_time;
	if (philo->data->all_alive)
		printf("%lld %d %s\n", timestamp, philo->id, status);
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
