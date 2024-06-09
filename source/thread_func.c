#include "philo.h"

void    *life(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    while(philo->ccu->all_alive || philo->finished)
    {
        
    }
}

void    *philo_parent(void *philo)
{
    philo = (t_philo *)philo;
}