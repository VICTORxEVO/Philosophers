/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:29:17 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/08/01 10:30:21 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	parent_action(t_all *ccu)
{
	int	i;
	int	status;

	i = -1;
	while (++i < ccu->n_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = -1;
			while (++i < ccu->n_philo)
				kill(ccu->pids[i], SIGTERM);
			return ;
		}
	}
	UNLOCK(ccu->pd_l);
	destroy(ccu);
}

void	*philo_parent(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (true)
	{
		usleep(2);
		LOCK(philo->ccu->pd_l);
		if ((size_t)(get_time() - philo->last_meal) > (size_t)philo->ccu->t_death)
		{
			printt(philo, 'D');
			exit(1);
		}
		UNLOCK(philo->ccu->pd_l);
		if (philo->ccu->n_meals != -1)
		{
			LOCK(philo->ccu->meal_l);
			if (philo->meal >= philo->ccu->n_meals)
			{
				philo->finished = true;
				return (UNLOCK(philo->ccu->meal_l), NULL);
			}
			UNLOCK(philo->ccu->meal_l);
		}
	}
	return (NULL);
}

void	*life(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	init_philo_needs(philo);
	special_philo(philo);
	while (true)
	{
		eat(philo);
		sleep_think(philo);
		usleep_v2((philo->ccu->t_death - (get_time() - philo->last_meal)) / 2);
	}
	return (NULL);
}
