/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:54:19 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/07/30 18:14:11 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	bool	is_finished(t_philo *philo)
{
	if (philo->ccu->n_meals != -1)
	{
		LOCK(&philo->ccu->meal_l);
		if (philo->finished)
			return (UNLOCK(&philo->ccu->meal_l), true);
		UNLOCK(&philo->ccu->meal_l);
	}
	return (false);
}

void	*life(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (special_philo(philo))
		return (NULL);
	while (true)
	{
		if (!eat(philo))
			break ;
		if (!sleep_think(philo))
			break ;
		if (is_finished(philo))
			break ;
		if (!usleep_v2((philo->ccu->t_death - (get_time() - philo->last_meal))
				/ 2, philo))
			break ;
	}
	return (NULL);
}
