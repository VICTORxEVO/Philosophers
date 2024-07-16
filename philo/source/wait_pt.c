#include "philo.h"

bool    wait_pt(t_all *ccu)
{
    int i;

    i = -1;
    while(++i < ccu->n_philo)
    {
        if (pthread_join(*ccu->philos[i].t, NULL) != 0)
            return (puterr_msg(&ccu->err, 't'), false);
        if (pthread_join(*ccu->philos[i].t_parent, NULL) != 0)
            return (puterr_msg(&ccu->err, 't'), false);
        if (ccu->n_meals != -1 && (*ccu->philos[i].t_hunger, NULL) != 0)
            return (puterr_msg(&ccu->err, 't'), false);
    }
    if (!destroy(ccu))
        return (false);
    return (true);
}