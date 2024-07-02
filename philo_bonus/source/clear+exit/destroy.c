#include "philo_bonus.h"

void    destroy(t_all *ccu)
{
    int i;

    if (ccu->err.err_str)
        free(ccu->err.err_str);
    i = -1;
    while (ccu->forks && ++i < ccu->n_philo)
        pthread_mutex_destroy(&ccu->forks[i]);
    if (ccu->forks)
        free(ccu->forks);
    i = -1;
    while (++i < ccu->n_philo && ccu->philos)
    {
        if (ccu->philos[i].t)
            free(ccu->philos[i].t);
        if (ccu->philos[i].t_parent)
            free(ccu->philos[i].t_parent);
    }
    if (ccu->philos)
        free(ccu->philos);
    free(ccu);
}
