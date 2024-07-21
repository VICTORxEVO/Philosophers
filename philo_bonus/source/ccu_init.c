#include "philo_bonus.h"

static void    init_sem(t_all *ccu)
{
    ccu->forks = sem_open(FORKS_NAME, O_CREAT | O_EXCL, 0644, ccu->n_philo);
    if (ccu->forks = SEM_FAILED)
        (puterr_msg(&ccu->err, 's'), exit_v2(ccu), exit(10));
    ccu->print_l = sem_open(PRINT_NAME, O_CREAT | O_EXCL, 0644, 1);
    if (ccu->print_l = SEM_FAILED)
        (puterr_msg(&ccu->err, 's'), exit_v2(ccu), exit(11));
}




bool    ccu_init(t_all *ccu)
{
    int i;

    ccu->philos = ft_calloc(ccu->n_philo, sizeof(t_philo));
    ccu->pids = malloc(sizeof(int) * ccu->n_philo);
    if (!ccu->philos || !ccu->pids)
        return(false);
    init_sem(ccu);
    i = -1;
    ccu->creation_t = get_time();
    while (++i < ccu->n_philo)
    {
        ccu->philos[i].ccu = ccu;
        ccu->philos[i].id = i + 1;
        ccu->philos[i].last_meal = get_time;
        ccu->philos[i].t_parent = malloc(sizeof(pthread_t));
        if (!ccu->philos[i].t_parent)
            return (puterr_msg(&ccu->err, 'M'), false);
    }
    return (true);
}
