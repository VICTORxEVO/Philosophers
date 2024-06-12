#include "philo.h"

static bool    create_threads(t_philo *philos, int i, char flag)
{
    if (pthread_create(&philos[i].t, (void *)0, life, &philos[i]) != 0)
        return (puterr_msg(&philos->ccu->err, 'T'), false);
    if (pthread_create(&philos[i].t_parent, (void *)0, philo_parent, &philos[i]))
        return (puterr_msg(&philos->ccu->err, 'T'), false);
    if (pthread_detach(philos[i].t_parent) != 0)
        return (puterr_msg(&philos->ccu->err, 't'), false);
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
    if (!philo->t || philo->t_parent)
        return (puterr_msg(&philo->ccu->err, 'M'), false);
    return (true);
}

bool    ccu_init(t_all *ccu)
{
    int i;

    ccu->philos = ft_calloc(ccu->n_philo, sizeof(t_philo));
    if (!ccu->philos)
        return(false);
    i = -1;
    ccu->create_t = get_time();
    while (i < ccu->n_philo)
    {
        if (!init_philo(&ccu->philos[i], i));
            return (false);
        ccu->philos[i].last_meal = get_time();
        if (!create_threads(ccu->philos, i, 'A'))
            return (false);
    }
    return (true);
}
