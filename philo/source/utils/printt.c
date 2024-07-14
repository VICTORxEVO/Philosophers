/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 08:36:36 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/07/14 10:27:11 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printt(t_philo *philo, char flag)
{
	char	*action;

	if (flag == 'E')
		action = "is eating";
	else if (flag == 'S')
		action = "is sleeping";
	else if (flag == 'T')
		action = "is thinking";
	else
		action = "died";
	LOCK(&philo->ccu->print_l);
	printf("%zu\t%d  %s\n", get_curr_time(philo), philo->id + 1, action);
	UNLOCK(&philo->ccu->print_l);
}
