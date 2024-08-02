/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 08:36:36 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/08/02 11:33:43 by ysbai-jo         ###   ########.fr       */
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
	{
		action = "died";
		printf("%s%zu\t%d  %s\n%s", CUR, get_curr_time(philo), philo->id,
			action, END);
		return ;
	}
	LOCK(philo->ccu->pd_l);
	printf("%s%zu\t%d  %s\n%s", CBB, get_curr_time(philo), philo->id, action,
		END);
	UNLOCK(philo->ccu->pd_l);
}
