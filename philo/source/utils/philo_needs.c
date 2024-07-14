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

bool    eat(t_philo *philo)
{
    if (!philo->ccu->all_alive)
        return (UNLOCK(&philo->ccu->forks[philo->l_fork]), UNLOCK(&philo->ccu->forks[philo->l_fork]), false);
    printt(philo, 'E');
    usleep(philo->ccu->t_eat * 1000);
    philo->last_meal = get_time();
    if (philo->ccu->n_meals != -1)
    {
        LOCK(&philo->ccu->meal_l);
        philo->meal++;
        UNLOCK(&philo->ccu->meal_l);
    }
    return (true);
}

bool    sleep_think(t_philo *philo)
{
    if (!philo->ccu->all_alive)
        return (false);
    printt(philo, 'S');
    usleep(philo->ccu->t_sleep * 1000);
    if (!philo->ccu->all_alive)
        return (false);
    printt(philo, 'T');
    return (true);
}