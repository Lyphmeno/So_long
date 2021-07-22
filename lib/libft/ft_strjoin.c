/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 10:51:16 by hlevi             #+#    #+#             */
/*   Updated: 2021/07/22 12:53:25 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!(s1 && s2))
		return (NULL);
	str = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(str))
		return (0);
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	return (str);
}
