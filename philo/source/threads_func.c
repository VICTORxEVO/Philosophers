#include "philo.h"

void    *life(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    while(true)
    {
        if (philo->ccu->n_philo == 1)
            return (usleep(10000000), NULL);
        if (!eat(philo))
            break ;
        if (!sleep_think(philo))
            break ;
        LOCK(&philo->ccu->meal_l);
        if (philo->finished)
            return (UNLOCK(&philo->ccu->meal_l), NULL);
        UNLOCK(&philo->ccu->meal_l);
    }
    return (NULL);
}

void    *philo_hunger(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    while (true)
    {
        LOCK(&philo->ccu->meal_l);
        if (philo->meal == philo->ccu->n_meals)
        {
            philo->finished = true;
            return (UNLOCK(&philo->ccu->meal_l), NULL);
        }
        UNLOCK(&philo->ccu->meal_l);
    }
    return (NULL);
}

void    *philo_parent(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    while(true)
    {
        LOCK(&philo->ccu->checker_l);
        if (!philo->ccu->all_alive)
            return (UNLOCK(&philo->ccu->checker_l), NULL);
        if ((philo->last_meal + philo->ccu->t_death) < get_time())
        {  
            philo->ccu->all_alive = false;
            UNLOCK(&philo->ccu->checker_l);
            printt(philo, 'D');
            break;
        }
        UNLOCK(&philo->ccu->checker_l); 
    }
    return (NULL);
}
