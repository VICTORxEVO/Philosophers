#include "philo.h"

void    *life(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    while(philo->ccu->all_alive || philo->finished)
    {
        grap_fork(philo->ccu->forks, philo->l_fork);
        if (philo->ccu->n_philo == 1)
        {
            usleep(1000000);
            return (NULL);
        }
        grap_fork(philo->ccu->forks, philo->r_fork);
        (eat(philo),down_fork(philo->ccu->forks, philo->l_fork, philo->r_fork));
        sleep_think(philo);
    }
    return (NULL);
}

void    *philo_parent(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    while(philo->ccu->all_alive || philo->finished)
    {
        if ((philo->last_meal + philo->ccu->t_death) >= get_time())
        {
            philo->ccu->all_alive = false;
            break;
        }
        if (philo->ccu->n_meals != -1 && philo->meal == philo->ccu->n_meals)
        {
            philo->finished = true;
            break;
        }
    }
    return (NULL);
}