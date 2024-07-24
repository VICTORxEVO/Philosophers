#include "philo.h"

static bool destroy_mtx(t_all *ccu)
{
    int i;

    i = -1;
    while (++i < ccu->n_philo)
        DSTR(&ccu->forks[i]);
    DSTR(&ccu->global_l);
    if (ccu->n_meals != -1)
        DSTR(&ccu->meal_l);
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
