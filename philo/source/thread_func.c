#include "philo.h"

void    *life(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    if (special_philo(philo))
        return (NULL);
    while(true)
    {
        if (!eat(philo))
            break ;
        if (philo->ccu->n_meals != -1)
        {
            LOCK(&philo->ccu->meal_l);
            if (philo->finished)
                return (UNLOCK(&philo->ccu->meal_l), NULL);
            UNLOCK(&philo->ccu->meal_l);
        }
        if (!sleep_think(philo))
            break ;
        usleep_v2((philo->ccu->t_death - (get_time() - philo->last_meal)) / 2);
    }
    return (NULL);
}
