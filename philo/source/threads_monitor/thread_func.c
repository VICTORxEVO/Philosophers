/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:54:19 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/07/26 10:54:20 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		if (philo->ccu->n_meals != -1)
		{
			LOCK(&philo->ccu->meal_l);
			if (philo->finished)
				return (UNLOCK(&philo->ccu->meal_l), NULL);
			UNLOCK(&philo->ccu->meal_l);
		}
		if (!sleep_think(philo))
			break ;
		usleep_v2((philo->ccu->t_death - (get_time() - philo->last_meal)) / 2);
	}
	return (NULL);
}
