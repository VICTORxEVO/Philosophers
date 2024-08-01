/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 08:36:36 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/08/01 09:13:15 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	printt(t_philo *philo, char flag)
{
	char	*action;

	if (flag == 'E')
		action = "is eating";
	else if (flag == 'S')
		action = "is sleeping";
	else if (flag == 'T')
		action = "is thinking";
	else if (flag == 'F')
		action = "has taken a fork";
	else
		action = "died";
	if (flag == 'D')
	{
		printf("%zu\t%d  %s\n", get_curr_time(philo), philo->id, action);
		return ;
	}
	LOCK(philo->ccu->pd_l);
	printf("%zu\t%d  %s\n", get_curr_time(philo), philo->id, action);
	UNLOCK(philo->ccu->pd_l);
}
