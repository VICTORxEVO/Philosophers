#include "philo.h"

bool    check_args(int ac, char *av[], t_all *ccu)
{
    int i;
    int j;

    if (ac < 5)
        return (puterr_msg(ccu->err, '-'), false);
    if (ac > 6)
        return (puterr_msg(ccu->err, '+'), false);
    i = -1;
    while (av[++i])
    {
        j = -1;
        while (av[i][++j])
        {
            if (!isdigit((int)av[i][j]))
                return (puterr_msg(ccu->err, 'N'), false);
        }
    }
    return (true);
}

bool    praser(int ac, char *av[], t_all **ccu)
{
    *ccu = ft_calloc(1, sizeof(t_all));
    if (!ccu || !check_args(ac, av, *ccu) || !init(ac, av, *ccu))
        return false;


}