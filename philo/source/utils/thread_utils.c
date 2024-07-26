/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:55:29 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/07/26 20:04:19 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	special_philo(t_philo *philo)
{
	if (philo->ccu->n_philo == 1)
	{
		LOCK(philo->l_fork);
		printt(philo, 'F');
		return (UNLOCK(philo->l_fork), true);
	}
	if (philo->id % 2)
		usleep_v2(2, philo);
	return (false);
}

static void	grap_forks(t_philo *philo)
{
	(LOCK(philo->l_fork), printt(philo, 'F'));
	(LOCK(philo->r_fork), printt(philo, 'F'));
}

static void	down_forks(t_philo *philo)
{
	UNLOCK(philo->r_fork);
	UNLOCK(philo->l_fork);
}

bool	eat(t_philo *philo)
{
	grap_forks(philo);
	printt(philo, 'E');
	LOCK(&philo->ccu->global_l);
	philo->last_meal = get_time();
	UNLOCK(&philo->ccu->global_l);
	if (!usleep_v2(philo->ccu->t_eat, philo))
		return (down_forks(philo), false);
	down_forks(philo);
	if (philo->ccu->n_meals != -1)
	{
		LOCK(&philo->ccu->meal_l);
		philo->meal++;
		UNLOCK(&philo->ccu->meal_l);
	}
	return (true);
}

bool	sleep_think(t_philo *philo)
{
	if (!check_alive(philo, 'N'))
		return (false);
	printt(philo, 'S');
	if (!usleep_v2(philo->ccu->t_sleep, philo))
		return (false);
	if (!check_alive(philo, 'N'))
		return (false);
	printt(philo, 'T');
	return (true);
}
