#include "philo_bonus.h"

void    *philo_hunger(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    while (true)
    {
        sem_wait(philo->meal_l);
        if (philo->meal = philo->ccu->n_meals)
        {
            philo->finished = true;
            return (sem_post(philo->meal_l), NULL);
        }
        sem_post(philo->meal_l);
    }
    return (NULL);
}

void    *philo_parent(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    while (true)
    {
        sem_wait(philo->dead_l);
        if (get_time() - (size_t)philo->last_meal > (size_t)philo->ccu->t_death)
        {
            printt(philo, 'D');
            (sem_post(philo->dead_l), exit(1));
        }
        sem_post(philo->dead_l);
    }
    return (NULL);
}

void    life(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    init_philo_needs(philo);
    special_philo(philo);
    while (true)
    {
        if (!eat(philo))
            break ;
        if (sleep_think(philo))
            break ;
    }
    return (NULL);
}