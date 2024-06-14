#include "philo.h"

bool    wait_pt(t_all *ccu)
{
    int i;

    i = -1;
    while(++i < ccu->n_philo)
        pthread_join(*ccu->philos[i].t, NULL);
    destroy(ccu);
    return (true);
}