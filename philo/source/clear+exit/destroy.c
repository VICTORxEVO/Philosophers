/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:53:04 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/07/26 12:50:04 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_mtx(t_all *ccu)
{
	int	i;

	i = -1;
	if (ccu->philos)
	{
		while (++i < ccu->n_philo)
			DSTR(&ccu->forks[i]);
		DSTR(&ccu->global_l);
		if (ccu->n_meals != -1)
			DSTR(&ccu->meal_l);
	}
}

bool	destroy(t_all *ccu)
{
	int	i;

	if (ccu->err.err_str)
		free(ccu->err.err_str);
	destroy_mtx(ccu);
	if (ccu->forks)
		free(ccu->forks);
	i = -1;
	while (++i < ccu->n_philo && ccu->philos)
	{
		if (ccu->philos[i].t)
			free(ccu->philos[i].t);
	}
	if (ccu->philos)
		free(ccu->philos);
	free(ccu);
	return (true);
}
