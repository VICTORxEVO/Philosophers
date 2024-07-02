#include "philo_bonus.h"

 
static bool init_mutex(t_all *ccu)
{
    int i;

    ccu->forks = malloc(sizeof(pthread_mutex_t) * ccu->n_philo);
    if (!ccu->forks)
        return (puterr_msg(&ccu->err, 'M'), false);
    i = -1;
    while(++i < ccu->n_philo)
    {
        if (pthread_mutex_init(&ccu->forks[i], (void *)0) != 0)
            return (puterr_msg(&ccu->err, 'T'), false);
    }
    return (true);
}

bool    ccu_init(t_all *ccu)
{
    int i;

    ccu->philos = ft_calloc(ccu->n_philo, sizeof(t_philo));
    ccu->pids = malloc(sizeof(int) * ccu->n_philo);
    if (!ccu->philos || !ccu->pids)
        return(false);
    if (!init_mutex(ccu))
        return (false);
    i = -1;
    ccu->creation_t = get_time();
}
