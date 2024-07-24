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
    }
    return (NULL);
}
