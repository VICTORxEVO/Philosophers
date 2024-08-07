/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:55:19 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/07/26 10:55:20 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	death_action(t_all *ccu, int i)
{
	ccu->all_alive = false;
	printt(&ccu->philos[i], 'D');
	UNLOCK(&ccu->global_l);
	return (true);
}

void	meal_action(t_all *ccu, int i, int *all_eat)
{
	if (!ccu->philos[i].finished)
	{
		if (ccu->philos[i].meal >= ccu->n_meals)
		{
			ccu->philos[i].finished = true;
			(*all_eat)++;
		}
	}
}
