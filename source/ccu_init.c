#include "philo.h"

bool    create_threads(t_philo *philos, int i, char flag)
{
    if (pthread_create(&philos[i].t, (void *)0, life, &philos[i]) != 0)
        return (puterr_msg(&philos->ccu->err, 'T'), false);
    if (pthread_create(&philos[i].t_parent, (void *)0, philo_parent, &philos[i]))
        return (puterr_msg(&philos->ccu->err, 'T'), false);
    if (pthread_detach(philos[i].t_parent) != 0)
        return (puterr_msg(&philos->ccu->err, 't'), false);
    return (true);
}

bool    ccu_init(t_all *ccu)
{
    int i;

    ccu->philos = ft_calloc(ccu->n_philo, sizeof(t_philo));
    if (!ccu->philos)
        return(false);
    i = -1;
    while (i < ccu->n_philo)
    {
        ccu->philos[i].id = i;
        ccu->philos[i].l_fork = i;
        ccu->philos[i].r_fork = i + 1;
        if (i == ccu->n_philo - 1)
            ccu->philos[i].r_fork = 0;
        ccu->philos[i].t = malloc(sizeof(pthread_t));
        ccu->philos[i].t_parent = malloc(sizeof(pthread_t));
        if (!ccu->philos[i].t || !ccu->philos[i].t_parent)
            return (puterr_msg(&ccu->err, 'M'), false);
        if (!create_threads(ccu->philos, i, 'A'))
            return (false);
    }
}
