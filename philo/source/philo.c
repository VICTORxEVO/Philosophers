/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:56:25 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/07/26 10:56:26 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_all	*ccu;

	ccu = ft_calloc(1, sizeof(t_all));
	if (!ccu || !parser(ac, av, ccu) || !ccu_init(ccu))
		return (exit_v2(ccu));
	if (!wait_pt(ccu))
		return (exit_v2(ccu));
	return (0);
}
