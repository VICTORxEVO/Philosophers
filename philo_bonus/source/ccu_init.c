#include "philo_bonus.h"

static void	init_sem(t_all *ccu)
{
    (sem_unlink(FORKS_SM), sem_unlink(PRINT_SM),
            sem_unlink(DEAD_SM), sem_unlink(MEAL_SM));
	ccu->forks = sem_open(FORKS_SM, O_CREAT, 0644, ccu->n_philo);
	ccu->pd_l = sem_open(DEAD_SM, O_CREAT | O_EXCL, 0644, 1);
	if (ccu->forks == (sem_t *)0 || ccu->pd_l == (sem_t *)0)
		(puterr_msg(&ccu->err, 's'),exit_v2(ccu), exit(11));
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
	ccu->pids = malloc(sizeof(int) * ccu->n_philo);
	if (!ccu->philos || !ccu->pids)
		return (false);
	init_sem(ccu);
	i = -1;
	ccu->creation_t = get_time();
	while (++i < ccu->n_philo)
	{
		ccu->philos[i].ccu = ccu;
		ccu->philos[i].id = i + 1;
		ccu->philos[i].last_meal = get_time();
	}
	return (true);
}
