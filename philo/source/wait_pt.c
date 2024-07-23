#include "philo.h"

static void    philo_parent(t_all *ccu)
{
    int i;
    int all_eat;

    all_eat = 0;
    i = -1;
    while(true)
    {
        while (++i < ccu->n_philo)
        {
            LOCK(&ccu->global_l);
            if ((get_time() - ccu->philos[i].last_meal) > (size_t)ccu->t_death)
            {
                ccu->all_alive = false;
                (printt(&ccu->philos[i], 'D'), UNLOCK(&ccu->global_l));
                return ;
            }
            if (ccu->n_meals != -1 && ccu->philos[i].meal >= ccu->n_meals && !ccu->philos[i].finished)
            {
                ccu->philos[i].finished = true;
                all_eat++;
            }
            UNLOCK(&ccu->global_l);
            if (all_eat == ccu->n_philo)
                return ;
        }
        i = -1;
    }
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