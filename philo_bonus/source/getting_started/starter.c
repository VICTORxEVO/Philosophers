/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:29:24 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/08/01 17:55:40 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static bool	init(char *av[], t_all *ccu)
{
	ccu->n_philo = ft_atoi(av[1]);
	ccu->t_death = ft_atoi(av[2]);
	ccu->t_eat = ft_atoi(av[3]);
	ccu->t_sleep = ft_atoi(av[4]);
	ccu->n_meals = -1;
	if (ccu->n_philo < 1)
		return (puterr_msg(&ccu->err, 'P'), false);
	if (ccu->n_philo < 1)
		return (puterr_msg(&ccu->err, 'L'), false);
	if (ccu->t_death < 1)
		return (puterr_msg(&ccu->err, 'D'), false);
	if (ccu->t_eat < 1)
		return (puterr_msg(&ccu->err, 'E'), false);
	if (ccu->t_sleep < 1)
		return (puterr_msg(&ccu->err, 'S'), false);
	if (av[5])
	{
		ccu->n_meals = ft_atoi(av[5]);
		if (ccu->n_meals < 1)
			return (puterr_msg(&ccu->err, 'F'), false);
	}
	return (true);
}

static bool	check_args(int ac, char *av[], t_all *ccu)
{
	int	i;
	int	j;

	if (ac < 5)
		return (puterr_msg(&ccu->err, '-'), false);
	if (ac > 6)
		return (puterr_msg(&ccu->err, '+'), false);
	i = 0;
	while (av[++i])
	{
		j = -1;
		if (ft_strlen(av[i]) > 8)
			return (puterr_msg2(&ccu->err, av[i], 'M'), false);
		while (av[i][++j])
		{
			if (!ft_isdigit((int)av[i][j]))
				return (puterr_msg2(&ccu->err, av[i], 'I'), false);
		}
	}
	return (true);
}

bool	parser(int ac, char *av[], t_all *ccu)
{
	if (!check_args(ac, av, ccu) || !init(av, ccu))
		return (NULL);
	return (ccu);
}

static void	init_sem(t_all *ccu)
{
	(sem_unlink(FORKS_SM), sem_unlink(PRINT_SM), sem_unlink(DEAD_SM),
		sem_unlink(MEAL_SM));
	ccu->forks = sem_open(FORKS_SM, O_CREAT | O_EXCL, 0644, ccu->n_philo);
	ccu->pd_l = sem_open(DEAD_SM, O_CREAT | O_EXCL, 0644, 1);
	if (ccu->forks == (sem_t *)0 || ccu->pd_l == (sem_t *)0)
		(puterr_msg(&ccu->err, 's'), exit_v2(ccu), exit(11));
	if (ccu->n_meals != -1)
	{
		ccu->meal_l = sem_open(MEAL_SM, O_CREAT | O_EXCL, 0644, 1);
		if (ccu->meal_l == (sem_t *)0)
			(puterr_msg(&ccu->err, 's'), exit(11));
	}
}

bool	ccu_init(t_all *ccu)
{
	int	i;

	ccu->philos = ft_calloc(ccu->n_philo, sizeof(t_philo));
	ccu->pids = malloc(sizeof(pid_t) * ccu->n_philo);
	if (!ccu->philos || !ccu->pids)
		return (false);
	init_sem(ccu);
	i = -1;
	ccu->creation_t = get_time();
	while (++i < ccu->n_philo)
	{
		ccu->philos[i].ccu = ccu;
		ccu->philos[i].id = i + 1;
		ccu->philos[i].t_parent = malloc(sizeof(pthread_t));
		if (!ccu->philos[i].t_parent)
			return (puterr_msg(&ccu->err, 'M'), false);
	}
	return (true);
}
