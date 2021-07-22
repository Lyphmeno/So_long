/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:42:13 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/07/22 20:46:10 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*source;

	i = 0;
	if (dst || src)
	{
		dest = (char *)dst;
		source = (char *)src;
		while (i < n)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (dst);
}
