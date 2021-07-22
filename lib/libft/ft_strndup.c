/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:20:42 by hlevi             #+#    #+#             */
/*   Updated: 2021/07/22 13:10:33 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, size_t n)
{
	size_t	i;
	char	*res;

	i = 0;
	res = malloc(sizeof(char) * (n + 1));
	if (!(res))
		return (0);
	while (src[i] && i < n && n > 0)
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
