#include "philo_bonus.h"

void    destroy_philos(t_philo *philo)
{
    t_all *ccu;

    ccu = philo->ccu;
    if (philo->ccu->err.err_str)
        free(philo->ccu->err.err_str);
    sem_close(philo->dead_l);
    if (philo->ccu->n_meals != -1)
        sem_close(philo->meal_l);
    if (pthread_join(philo->t_parent, (void *)0))
        exit(1);
    free(philo->t_parent);
    free(philo->ccu->philos);
    free(ccu);
}

void    destroy(t_all *ccu)
{
    int i;

    if (ccu->err.err_str)
        free(ccu->err.err_str);
    destroy_sems(ccu);
    if (ccu->forks)
        free(ccu->forks);
    if (ccu->philos)
        free(ccu->philos);
    free(ccu);
}
