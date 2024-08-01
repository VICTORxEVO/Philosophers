/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:12:24 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/08/01 17:50:54 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	destroy_philos(t_philo *philo)
{
	t_all	*ccu;

	if (pthread_join(*philo->t_parent, (void *)0) != 0)
		exit(1);
	ccu = philo->ccu;
	sem_close(ccu->pd_l);
	if (ccu->n_meals != -1)
		sem_close(ccu->meal_l);
	free(philo->t_parent);
	free(philo->ccu->philos);
	free(ccu);
	exit(0);
}

void	destroy(t_all *ccu)
{
	int i;

	if (ccu->err.err_str)
		free(ccu->err.err_str);
	(sem_unlink(FORKS_SM), sem_close(ccu->forks));
	(sem_unlink(DEAD_SM), sem_close(ccu->pd_l));
	if (ccu->n_meals != -1)
		(sem_unlink(MEAL_SM), sem_close(ccu->meal_l));
	i = -1;
	while (++i < ccu->n_philo)
	{
		if (ccu->philos[i].t_parent)
			free(ccu->philos[i].t_parent);
	}
	if (ccu->philos)
		free(ccu->philos);
	free(ccu);
}
