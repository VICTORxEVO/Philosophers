#include "philo.h"

static bool    philo_parent(t_all *ccu)
{
    int (i), (all_eat);

    i = -1;
    all_eat = 0;
    while(true)
    {
        while (++i < ccu->n_philo)
        {
            LOCK(&ccu->global_l);
            if ((get_time() - ccu->philos[i].last_meal) > (size_t)ccu->t_death)
                return (death_action(ccu, i));
            UNLOCK(&ccu->global_l);
            if (ccu->n_meals != -1)
                (LOCK(&ccu->meal_l), meal_action(ccu, i, &all_eat), UNLOCK(&ccu->meal_l));
            if (all_eat == ccu->n_philo)
                return (true);
        }
        i = -1;
    }
    return (true);
}

bool    wait_pt(t_all *ccu)
{
    int i;

    philo_parent(ccu);
    i = -1;
    while(++i < ccu->n_philo)
    {
        if (pthread_join(*ccu->philos[i].t, NULL) != 0)
            return (puterr_msg(&ccu->err, 't'), false);
    }
    if (!destroy(ccu))
        return (false);
    return (true);
}