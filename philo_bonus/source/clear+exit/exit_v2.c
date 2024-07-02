#include "philo_bonus.h"

int exit_v2(t_all *ccu)
{
    if (!ccu)
        return (puterr(MALLOC_ERR), 1);
    puterr("philo: ");
    puterr(ccu->err.err_str);
    puterr("\n");
    destroy(ccu);
    return (2);
}