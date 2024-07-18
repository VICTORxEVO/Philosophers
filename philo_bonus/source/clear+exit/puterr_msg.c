#include "philo_bonus.h"

void	puterr_msg2(t_err *err, char *str, char flag)
{
	if (flag == 'M')
		err->err_str = ft_strjoin(str, ": too large number");
	else if (flag == 'I')
		err->err_str = ft_strjoin(str, ": argument must be a number");
}

static void puterr_msg_extra(t_err *err, char flag)
{
	if (flag == 's')
		err->err_str = ft_strdup("semaphore: creation failed !");
	else if (flag == 'f')
		err->err_str = ft_strdup("fork: processe creation failed !");
}

void	puterr_msg(t_err *err, char flag)
{
	if (flag == '-')
		err->err_str = ft_strdup("too few arguments");
	else if (flag == '+')
		err->err_str = ft_strdup("too many arguments");
	else if (flag == 'F')
		err->err_str = ft_strdup("number of Meals must be more than 0");
	else if (flag == 'P')
		err->err_str = ft_strdup("number of philos must be more than 0");
	else if (flag == 'L')
		err->err_str = ft_strdup("number of philos shouldn't \
                be more than 200");
	else if (flag == 'D')
		err->err_str = ft_strdup("time to die must be more than 60 ms");
	else if (flag == 'E')
		err->err_str = ft_strdup("time to eat must be more than 60 ms");
	else if (flag == 'S')
		err->err_str = ft_strdup("time to sleep must be more than 60 ms");
	else if (flag == 'M')
		err->err_str = ft_strdup("malloc: memory allocation failed !");
	else
		puterr_msg_extra(err, flag);
}
