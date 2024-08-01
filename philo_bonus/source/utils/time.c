/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:12:57 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/08/01 09:32:09 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000LL) + (time.tv_usec / 1000LL));
}

size_t	get_curr_time(t_philo *philo)
{
	size_t	time;

	time = get_time() - philo->ccu->creation_t;
	return (time);
}

void	usleep_v2(size_t ms)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < ms)
		usleep(500);
}
