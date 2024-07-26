/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_v2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:53:06 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/07/26 12:48:47 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
