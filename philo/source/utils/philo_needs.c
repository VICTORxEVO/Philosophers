#include "philo.h"

static void    grap_forks(t_philo *philo)
{
    LOCK(philo->l_fork);
    LOCK(philo->r_fork);
}

static void    down_forks(t_philo *philo)
{
    UNLOCK(philo->r_fork);
    UNLOCK(philo->l_fork);
}

bool    eat(t_philo *philo)
{
    grap_forks(philo);
    LOCK(&philo->ccu->checker_l);
    if (!philo->ccu->all_alive)
        return(UNLOCK(&philo->ccu->checker_l), down_forks(philo), false);
    UNLOCK(&philo->ccu->checker_l);
    printt(philo, 'E');
    usleep(philo->ccu->t_eat * 1000);
    LOCK(&philo->ccu->checker_l);
    philo->last_meal = get_time();
    UNLOCK(&philo->ccu->checker_l);
    if (philo->ccu->n_meals != -1)
    {
        LOCK(&philo->ccu->meal_l);
        philo->meal++;
        UNLOCK(&philo->ccu->meal_l);
    }
    down_forks(philo);
    return (true);
}

bool    sleep_think(t_philo *philo)
{
    LOCK(&philo->ccu->checker_l);
    if (!philo->ccu->all_alive)
        return (UNLOCK(&philo->ccu->checker_l), false);
    UNLOCK(&philo->ccu->checker_l);
    printt(philo, 'S');
    usleep(philo->ccu->t_sleep * 1000);
    LOCK(&philo->ccu->checker_l);
    if (!philo->ccu->all_alive)
        return (UNLOCK(&philo->ccu->checker_l), false);
    UNLOCK(&philo->ccu->checker_l);
    printt(philo, 'T');
    return (true);
}
