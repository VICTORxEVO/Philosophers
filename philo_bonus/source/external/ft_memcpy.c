/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:49:00 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/06/09 09:37:37 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	b;

	if (!dest && !src)
		return (NULL);
	b = 0;
	while (b < n && dest != src)
	{
		*((unsigned char *)(dest + b)) = *((const unsigned char *)(src + b));
		++b;
	}
	return (dest);
}
