/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccu_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:53:47 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/07/26 20:07:57 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static bool	create_threads(t_philo *philo)
// {
// 	philo->last_meal = get_time();
// 	if (pthread_create(philo->t, (void *)0, life, philo) != 0)
// 		return (puterr_msg(&philo->ccu->err, 'T'), false);
// 	return (true);
// }

static bool	init_philo(t_philo *philo, int i, t_all *ccu)
{
	philo->t = malloc(sizeof(pthread_t));
	if (!philo->t)
		return (puterr_msg(&philo->ccu->err, 'M'), false);
	philo->ccu = ccu;
	philo->id = i + 1;
	philo->l_fork = &philo->ccu->forks[i];
	philo->r_fork = &philo->ccu->forks[(i + 1) % philo->ccu->n_philo];
	if (i == philo->ccu->n_philo - 1)
	{
		philo->l_fork = &philo->ccu->forks[0];
		philo->r_fork = &philo->ccu->forks[i];
	}
	return (true);
}

static bool	init_mutex(t_all *ccu)
{
	int	i;

	ccu->forks = malloc(sizeof(pthread_mutex_t) * ccu->n_philo);
	if (!ccu->forks)
		return (puterr_msg(&ccu->err, 'M'), false);
	i = -1;
	while (++i < ccu->n_philo)
	{
		if (pthread_mutex_init(&ccu->forks[i], (void *)0) != 0)
			return (puterr_msg(&ccu->err, 'T'), false);
	}
	if (pthread_mutex_init(&ccu->global_l, (void *)0) != 0)
		return (puterr_msg(&ccu->err, 'T'), false);
	if (ccu->n_meals != -1)
	{
		if (pthread_mutex_init(&ccu->global_l, (void *)0) != 0)
			return (puterr_msg(&ccu->err, 'T'), false);
	}
	return (true);
}

bool	ccu_init(t_all *ccu)
{
	int	i;

	ccu->philos = ft_calloc(ccu->n_philo, sizeof(t_philo));
	if (!ccu->philos)
		return (false);
	if (!init_mutex(ccu))
		return (false);
	i = -1;
	ccu->creation_t = get_time();
	while (++i < ccu->n_philo)
	{
		if (!init_philo(&ccu->philos[i], i, ccu))
			return (false);
	}
	i = -1;
	while (++i < ccu->n_philo)
	{
		ccu->philos[i].last_meal = get_time();
		if (pthread_create(ccu->philos[i].t, (void *)0, life, &ccu->philos[i]) != 0)
			return (puterr_msg(&ccu->err, 'T'), false);
	}
	return (true);
}
