#include "philo.h"

int exit_v2(t_all *ccu)
{
    if (!ccu)
        return (puterr(MALLOC_ERR), 1);
    puterr(ccu->err.err_str);
    destroy(ccu);
    return (2);
}