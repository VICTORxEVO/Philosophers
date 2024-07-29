#include "philo_bonus.h"

void    *philo_parent(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    while (true)
    {
        LOCK(philo->ccu->pd_l);
        if ((get_time() - philo->last_meal) > (size_t)philo->ccu->t_death)
        {
            printt(philo, 'D');
            exit(1);
        }
        UNLOCK(philo->ccu->pd_l);
        if (philo->ccu->n_meals != -1)
        {
            LOCK(philo->ccu->meal_l);
            if (philo->meal == philo->ccu->n_meals)
            {
                philo->finished = true;
                return (UNLOCK(philo->ccu->meal_l), NULL);
            }
            UNLOCK(philo->ccu->meal_l);
        }
    }
    return (NULL);
}

void    *life(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    init_philo_needs(philo);
    special_philo(philo);
    while (true)
    {
        eat(philo);
        sleep_think(philo);
        usleep_v2((philo->ccu->t_death - (get_time() - philo->last_meal)) / 2);
    }
    return (NULL);
}