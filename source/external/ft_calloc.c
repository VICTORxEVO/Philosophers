/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:48:04 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/06/08 18:59:24 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	ptr = malloc(n * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, n * size);
	return (ptr);
}
