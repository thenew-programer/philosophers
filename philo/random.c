/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:46:12 by ybouryal          #+#    #+#             */
/*   Updated: 2025/02/26 11:50:22 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// Function to generate a random number using a given seed
unsigned int ft_rand(unsigned int *seed)
{
    *seed = (*seed * A + C) % M;
    return *seed;
}

// Initialize the random seed using current time
unsigned int ft_srand(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (unsigned int)(tv.tv_sec ^ tv.tv_usec);
}

// Get a random number in a specific range [min, max]
unsigned int ft_rand_range(unsigned int *seed, unsigned int min, unsigned int max)
{
    return min + (ft_rand(seed) % (max - min + 1));
}
