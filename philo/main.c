/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:17:23 by ybouryal          #+#    #+#             */
/*   Updated: 2025/02/25 11:53:48 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (parse_args(ac, av, &data) == -1)
		return (1);
	if (init_simulation(&data) == -1)
		return (1);
	start_simulation(&data);
	cleanup(&data);
	return (0);
}
