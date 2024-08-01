/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:13:08 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/08/01 17:52:52 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_philo_needs(t_philo *philo)
{
	philo->ccu->pd_l = sem_open(DEAD_SM, 0);
	if (philo->ccu->pd_l == SEM_FAILED)
		(puterr_msg(&philo->ccu->err, 's'), exit(2));
	if (philo->ccu->n_meals != -1)
	{
		philo->ccu->meal_l = sem_open(MEAL_SM, 0);
		if (philo->ccu->meal_l == SEM_FAILED)
			(puterr_msg(&philo->ccu->err, 's'), exit_v2(philo->ccu), exit(1));
	}
	if (pthread_create(philo->t_parent, (void *)0, philo_parent, philo) != 0)
		(puterr_msg(&philo->ccu->err, 'M'), exit(1));
}

void	special_philo(t_philo *philo)
{
	if (philo->ccu->n_philo == 1)
		(printt(philo, 'F'), usleep_v2(philo->ccu->t_death + 20));
	if (philo->id % 2)
		 usleep_v2(2);
}

bool	eat(t_philo *philo)
{
	grap_forks(philo);
	printt(philo, 'E');
	LOCK(philo->ccu->pd_l);
	philo->last_meal = get_time();
	UNLOCK(philo->ccu->pd_l);
	usleep_v2((size_t)philo->ccu->t_eat);
	if (philo->ccu->n_meals != -1)
	{
		LOCK(philo->ccu->meal_l);
		philo->meal++;
		UNLOCK(philo->ccu->meal_l);
	}
	down_forks(philo);
	return (true);
}

bool	sleep_think(t_philo *philo)
{
	if (philo->ccu->n_meals != -1)
	{
		LOCK(philo->ccu->meal_l);
		if (philo->finished)
			(UNLOCK(philo->ccu->meal_l), destroy_philos(philo));
		UNLOCK(philo->ccu->meal_l);
	}
	printt(philo, 'S');
	usleep_v2((size_t)philo->ccu->t_sleep);
	printt(philo, 'T');
	return (true);
}
