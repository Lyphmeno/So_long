/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartostring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:23:13 by hlevi             #+#    #+#             */
/*   Updated: 2021/07/22 13:14:00 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chartostring(int c)
{
	char	*str;

	str = ft_calloc(sizeof(char), 2);
	if (!(str))
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}
