#include "philo.h"


bool    death_action(t_all *ccu, int i)
{
    ccu->all_alive = false;
    printt(&ccu->philos[i], 'D');
    UNLOCK(&ccu->global_l);
    return (true);
}

void    meal_action(t_all *ccu, int i, int *all_eat)
{
    if (!ccu->philos[i].finished)
    {
        if (ccu->philos[i].meal >= ccu->n_meals)
        {
            ccu->philos[i].finished = true;
            (*all_eat)++;
        }
    }
}
