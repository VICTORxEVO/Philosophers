#include "philo.h"

static bool init(char *av[], t_all *ccu)
{
    ccu->n_philo = ft_atoi(av[1]);
    ccu->t_death = ft_atoi(av[2]);
    ccu->t_eat = ft_atoi(av[3]);
    ccu->t_sleep = ft_atoi(av[4]);
    ccu->n_meals = -1;
    if (ccu->n_philo < 1)
        return (puterr_msg(&ccu->err, 'P'), false);
    // if (ccu->n_philo > 200)
    //     return (puterr_msg(&ccu->err, 'L'), false);
    if (ccu->t_death < 1)
        return (puterr_msg(&ccu->err, 'D'), false);
    if (ccu->t_eat < 1)
        return (puterr_msg(&ccu->err, 'E'), false);
    if (ccu->t_sleep < 1)
        return (puterr_msg(&ccu->err, 'S'), false);
    if (av[5])
    {
        ccu->n_meals = ft_atoi(av[5]);
        if (ccu->n_meals < 1)
            return (puterr_msg(&ccu->err, 'F'), false);
    }
    ccu->all_alive = 1;
    return (true);
}

static bool check_args(int ac, char *av[], t_all *ccu)
{
    int i;
    int j;

    if (ac < 5)
        return (puterr_msg(&ccu->err, '-'), false);
    if (ac > 6)
        return (puterr_msg(&ccu->err, '+'), false);
    i = 0;
    while (av[++i])
    {
        j = -1;
        if (ft_strlen(av[i]) > 8)
            return (puterr_msg2(&ccu->err, av[i], 'M'), false);
        while (av[i][++j])
        {
            if (!ft_isdigit((int)av[i][j]))
                return (puterr_msg2(&ccu->err, av[i], 'I'), false);
        }
    }
    return (true);
}

bool    parser(int ac, char *av[], t_all *ccu)
{
    if (!check_args(ac, av, ccu) || !init(av, ccu))
        return (NULL);
    return (ccu);
}