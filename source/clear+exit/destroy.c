#include "philo.h"

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
    if (ccu->philos)
        free(ccu->philos);
    free(ccu);
}
