/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils_R1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:55:27 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/07/26 17:30:28 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	usleep_v2(size_t ms, t_philo *philo)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < ms)
	{
		LOCK(&philo->ccu->global_l);
		if (!philo->ccu->all_alive)
			return (UNLOCK(&philo->ccu->global_l), false);
		UNLOCK(&philo->ccu->global_l);
	}
	return (true);
}

bool	check_alive(t_philo *philo, char flag)
{
	bool	status;

	status = true;
	LOCK(&philo->ccu->global_l);
	if (!philo->ccu->all_alive)
		status = false;
	else
		return (UNLOCK(&philo->ccu->global_l), status);
	UNLOCK(&philo->ccu->global_l);
	if (flag == 'L')
		return (UNLOCK(philo->l_fork), status);
	else if (flag == 'R')
		return (UNLOCK(philo->r_fork), status);
	else if (flag == 'B')
		return (UNLOCK(philo->l_fork), UNLOCK(philo->r_fork), status);
	else
		return (status);
}
