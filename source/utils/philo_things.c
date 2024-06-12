#include "philo.h"

void    grap_fork(pthread_mutex_t *fork, int i)
{
    LOCK(&fork[i]);
}

void    down_fork(pthread_mutex_t *fork, int lf, int rf)
{
    UNLOCK(&fork[lf]);
    UNLOCK(&fork[rf]);
}

void    eat(t_philo *philo)
{
    printt(philo, 'E');
    usleep(philo->ccu->t_eat * 1000);
}

void    sleep_think(t_philo *philo)
{
    printt(philo, 'S');
    usleep(philo->ccu->t_sleep * 1000);
    printt(philo, 'T');
}