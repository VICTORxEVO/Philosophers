/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_R1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:13:02 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/08/01 09:31:58 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	grap_forks(t_philo *philo)
{
	(LOCK(philo->ccu->forks), printt(philo, 'F'));
	(LOCK(philo->ccu->forks), printt(philo, 'F'));
}

void	down_forks(t_philo *philo)
{
	UNLOCK(philo->ccu->forks);
	UNLOCK(philo->ccu->forks);
}
