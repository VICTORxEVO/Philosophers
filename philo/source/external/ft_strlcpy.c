/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:28:56 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/06/09 09:35:44 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	x;

	x = 0;
	if (size)
	{
		while (src[x] && x < (size - 1))
		{
			dest[x] = src[x];
			x++;
		}
		dest[x] = 0;
	}
	return (ft_strlen(src));
}
