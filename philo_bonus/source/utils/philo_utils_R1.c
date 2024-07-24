#include "philo_bonus.h"

void    grap_forks(t_philo *philo)
{
    if (!(philo->id % 2))
        usleep_v2(2);
    (LOCK(philo->ccu->forks), printt(philo, 'F'));
    (LOCK(philo->ccu->forks), printt(philo, 'F'));
}

void    down_forks(t_philo *philo)
{
    UNLOCK(philo->ccu->forks);
    UNLOCK(philo->ccu->forks);
}