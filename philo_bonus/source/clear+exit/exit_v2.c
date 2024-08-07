/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_v2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:12:27 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/08/01 09:30:21 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	exit_v2(t_all *ccu)
{
	if (!ccu)
		return (puterr(MALLOC_ERR), 1);
	puterr("philo: ");
	puterr(ccu->err.err_str);
	puterr("\n");
	destroy(ccu);
	return (2);
}
