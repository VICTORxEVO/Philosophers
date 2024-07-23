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
        LOCK(&philo->ccu->global_l);
        if (philo->finished)
            return (UNLOCK(&philo->ccu->global_l), NULL);
        UNLOCK(&philo->ccu->global_l);
        if (!sleep_think(philo))
            break ;
    }
    return (NULL);
}
