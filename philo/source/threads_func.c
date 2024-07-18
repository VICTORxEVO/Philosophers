#include "philo.h"

void    *life(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    while(true)
    {
        if (special_philo(philo))
            return (NULL);
        if (!eat(philo))
            break ;
        LOCK(&philo->ccu->meal_l);
        if (philo->finished)
            return (UNLOCK(&philo->ccu->meal_l), NULL);
        UNLOCK(&philo->ccu->meal_l);
        if (!sleep_think(philo))
            break ;
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
        if (!philo->ccu->all_alive || philo->finished)
            return (UNLOCK(&philo->ccu->checker_l), NULL);
        if ((size_t)(philo->last_meal + (size_t)philo->ccu->t_death) < get_time())
        {  
            philo->ccu->all_alive = false;
            UNLOCK(&philo->ccu->checker_l);
            printt(philo, 'D');
            return (NULL);
        }
        UNLOCK(&philo->ccu->checker_l); 
    }
    return (NULL);
}
