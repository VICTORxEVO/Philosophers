#include "philo.h"

bool    special_philo(t_philo *philo)
{
    if (philo->ccu->n_philo == 1)
        return (printt(philo, 'L'), usleep(philo->ccu->t_death * 1000 + 100), true);
    else if (philo->id % 2 == 0)
        usleep(2);
    return (false);
}

static bool    grap_forks(t_philo *philo)
{
    if (philo->id % 2 == 0)
    {
        (LOCK(philo->r_fork), printt(philo, 'R'));
        if (!check_alive(philo, 'R'))
            return (false);
        (LOCK(philo->l_fork), printt(philo, 'L'));
        if (!check_alive(philo, 'B'))
            return (false);
        return (true);
    }
    LOCK(philo->l_fork);
    if (!check_alive(philo, 'L'))
        return (false);
    printt(philo, 'L');
    LOCK(philo->r_fork), printt(philo, 'R');
    if (!check_alive(philo, 'B'))
        return (false);
    return (true);
}

static void    down_forks(t_philo *philo)
{
    if (philo->id % 2 == 0)
    {
        (UNLOCK(philo->l_fork), UNLOCK(philo->r_fork));
        return ;
    }
    UNLOCK(philo->r_fork);
    UNLOCK(philo->l_fork);
}

bool    eat(t_philo *philo)
{
    if (!grap_forks(philo))
        return (false);
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
    if (!check_alive(philo, 'N'))
        return (false);
    printt(philo, 'S');
    usleep(philo->ccu->t_sleep * 1000);
    if (!check_alive(philo, 'N'))
        return (false);
    printt(philo, 'T');
    return (true);
}
