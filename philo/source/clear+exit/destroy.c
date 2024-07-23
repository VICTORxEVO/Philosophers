#include "philo.h"

static bool destroy_mtx(t_all *ccu)
{
    int i;

    i = -1;
    while (++i < ccu->n_philo)
    {
        if (DSTR(&ccu->forks[i]) != 0)
            return (puterr_msg(&ccu->err, 'd'), false);
    }
    if (DSTR(&ccu->global_l))
        return (puterr_msg(&ccu->err, 'd'), false);
    return (true);
}

bool    destroy(t_all *ccu)
{
    int i;

    if (ccu->err.err_str)
        free(ccu->err.err_str);
    if (!destroy_mtx(ccu))
        return (false);
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
