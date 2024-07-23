#include "philo.h"


bool    check_alive(t_philo *philo, char flag)
{
    bool    status;

    status = true;
    LOCK(&philo->ccu->global_l);
    if (!philo->ccu->all_alive)
        status = false;
    else
        return (UNLOCK(&philo->ccu->global_l), status);
    UNLOCK(&philo->ccu->global_l);
    if (flag == 'L')
        return (UNLOCK(philo->l_fork), status);
    else if (flag == 'R')
        return (UNLOCK(philo->r_fork), status);
    else if (flag == 'B')
        return (UNLOCK(philo->l_fork), UNLOCK(philo->r_fork), status);
    else
        return (status);
}
