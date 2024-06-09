#include "philo.h"

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
            return (false);
        pthread_create(&ccu->philos[i].t, (void *)0, life, &ccu->philos[i]);
        pthread_create(&ccu->philos[i].t_parent, (void *)0, philo_parent, &ccu->philos[i]);
        pthread_detach(ccu->philos[i].t_parent);
    }
    if (ccu->n_meals > 0)

}
