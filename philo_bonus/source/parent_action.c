#include "philo_bonus.h"

void    parent_action(t_all *ccu)
{
    int i;
    int status;

    i = -1;
    while (++i < ccu->n_philo)
    {
        waitpid(-1, &status, 0);
        if (status != 0)
        {
            i = -1;
            while (++i < ccu->n_philo)
                kill(ccu->pids[i], SIGTERM)
        }
    }
}