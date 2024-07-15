#include "philo.h"

static bool    create_threads(t_philo *philo)
{
    philo->last_meal = get_time();
    if (pthread_create(philo->t, (void *)0, life, philo) != 0)
        return (puterr_msg(&philo->ccu->err, 'T'), false);
    if (pthread_create(philo->t_parent, (void *)0, philo_parent, philo) != 0)
        return (puterr_msg(&philo->ccu->err, 'T'), false);
    if (philo->ccu->n_meals != -1)
    {
        if (pthread_create(philo->t_hunger, (void *)0, philo_hunger, philo) != 0)
            return (puterr_msg(&philo->ccu->err, 'T'), false);
        if (pthread_detach(*philo->t_hunger) != 0)
            return (puterr_msg(&philo->ccu->err, 't'), false);
    }
    if (pthread_detach(*philo->t_parent) != 0)
        return (puterr_msg(&philo->ccu->err, 't'), false);
    return (true);
}
static bool    init_philo(t_philo *philo, int i)
{
    philo->t = malloc(sizeof(pthread_t));
    philo->t_parent = malloc(sizeof(pthread_t));
    if (philo->ccu->n_meals != -1)
    {
        philo->t_hunger = malloc(sizeof(pthread_t));
        if (!philo->t_hunger)
            return (puterr_msg(&philo->ccu->err, 'M'), false);
    }
    if (!philo->t || !philo->t_parent)
        return (puterr_msg(&philo->ccu->err, 'M'), false);
    philo->id = i;
    if (i == philo->ccu->n_philo - 1)
    {
        philo->l_fork = &philo->ccu->forks[0];
        philo->r_fork= &philo->ccu->forks[i];
        return (true);
    }
    philo->l_fork = &philo->ccu->forks[i];
    philo->r_fork= &philo->ccu->forks[i + 1];
    return (true);
}
 
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
    if (pthread_mutex_init(&ccu->print_l, (void *)0) != 0)
            return (puterr_msg(&ccu->err, 'T'), false);
    if (pthread_mutex_init(&ccu->meal_l, (void *)0) != 0)
            return (puterr_msg(&ccu->err, 'T'), false);
    if (pthread_mutex_init(&ccu->checker_l, (void *)0) != 0)
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
        if (!create_threads(&ccu->philos[i]))
            return (false);
    }
    return (true);
}
