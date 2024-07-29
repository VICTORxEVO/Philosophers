#include "philo_bonus.h"

void    destroy_philos(t_philo *philo)
{
    t_all *ccu;

    ccu = philo->ccu;
    if (philo->ccu->err.err_str)
        free(philo->ccu->err.err_str);
    sem_close(ccu->pd_l);
    if (philo->ccu->n_meals != -1)
        sem_close(ccu->meal_l);
    if (pthread_join(*philo->t_parent, (void *)0) != 0)
        exit(1);
    free(philo->t_parent);
    free(philo->ccu->philos);
    free(ccu);
    exit(0);
}

void    destroy(t_all *ccu)
{
    if (ccu->err.err_str)
        free(ccu->err.err_str);
    if (ccu->forks || ccu->pd_l || ccu->meal_l)
    (sem_unlink(FORKS_SM), sem_close(ccu->forks));
    (sem_unlink(DEAD_SM), sem_close(ccu->pd_l));
    if (ccu->n_meals != -1)
        (sem_unlink(MEAL_SM), sem_close(ccu->meal_l));
    if (ccu->philos)
        free(ccu->philos);
    free(ccu);
}
