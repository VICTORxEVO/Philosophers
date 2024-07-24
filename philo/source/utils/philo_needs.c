#include "philo.h"

bool    special_philo(t_philo *philo)
{
    if (philo->ccu->n_philo == 1)
        return (printt(philo, 'F'), usleep_v2(philo->ccu->t_death + 10), true);
    return (false);
}

static void    grap_forks(t_philo *philo)
{
    (LOCK(philo->l_fork), printt(philo, 'F'));
    (LOCK(philo->r_fork), printt(philo, 'F'));
}

static void    down_forks(t_philo *philo)
{
    UNLOCK(philo->r_fork);
    UNLOCK(philo->l_fork);
}

bool    eat(t_philo *philo)
{
    grap_forks(philo);
    printt(philo, 'E');
    LOCK(&philo->ccu->global_l);
    philo->last_meal = get_time();
    UNLOCK(&philo->ccu->global_l);
    usleep_v2(philo->ccu->t_eat);
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
    if (!check_alive(philo, 'N'))
        return (false);
    printt(philo, 'S');
    usleep_v2(philo->ccu->t_sleep);
    if (!check_alive(philo, 'N'))
        return (false);
    printt(philo, 'T');
    return (true);
}
