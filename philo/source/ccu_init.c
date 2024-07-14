#include "philo.h"

static bool    create_threads(t_philo *philo)
{
    if (pthread_create(philo->t, (void *)0, life, philo) != 0)
        return (puterr_msg(&philo->ccu->err, 'T'), false);
    if (pthread_create(philo->t_parent, (void *)0, philo_parent, philo) != 0)
        return (puterr_msg(&philo->ccu->err, 'T'), false);
    if (pthread_detach(*philo->t_parent) != 0)
        return (puterr_msg(&philo->ccu->err, 't'), false);
    return (true);
}
static bool    init_philo(t_philo *philo, int i)
{
    philo->id = i;
    philo->l_fork = i;
    philo->r_fork= i + 1;
    if (i == philo->ccu->n_philo - 1)
        philo->r_fork = 0;
    philo->t = malloc(sizeof(pthread_t));
    philo->t_parent = malloc(sizeof(pthread_t));
    if (!philo->t || !philo->t_parent)
        return (puterr_msg(&philo->ccu->err, 'M'), false);
    return (true);
}
 
static bool init_mutex(t_all *ccu)
{
    int i;

    ccu->forks = malloc(sizeof(pthread_mutex_t) * ccu->n_philo);
    ccu->locker = malloc(sizeof(pthread_mutex_t));
    if (!ccu->forks || !ccu->locker)
        return (puterr_msg(&ccu->err, 'M'), false);
    i = -1;
    while(++i < ccu->n_philo)
    {
        if (pthread_mutex_init(&ccu->forks[i], (void *)0) != 0)
            return (puterr_msg(&ccu->err, 'T'), false);
    }
    if (pthread_mutex_init(ccu->locker, (void *)0) != 0)
            return (puterr_msg(&ccu->err, 'T'), false);
    return (true);
}

bool    ccu_init(t_all *ccu)
{
    int i;

    ccu->philos = ft_calloc(ccu->n_philo, sizeof(t_philo));
    if (!ccu->philos)
        return(false);
    if (!init_mutex(ccu))
        return (false);
    i = -1;
    ccu->creation_t = get_time();
    while (++i < ccu->n_philo)
    {
        ccu->philos[i].ccu = ccu;
        if (!init_philo(&ccu->philos[i], i))
            return (false);
        ccu->philos[i].last_meal = get_time();
        if (!create_threads(&ccu->philos[i]))
            return (false);
    }
    return (true);
}
