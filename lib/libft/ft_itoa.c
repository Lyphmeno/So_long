/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyphmeno <lyphmeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:33:18 by hlevi             #+#    #+#             */
/*   Updated: 2021/07/26 15:05:37 by lyphmeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numbers(unsigned int n)
{
	int	counter;

	if (n == 0)
		return (1);
	counter = 0;
	while (n > 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	int				i;
	unsigned int	nb;
	char			*s;

	nb = n;
	s = (char *)malloc((sizeof(char) * (ft_numbers(nb) + 1)));
	if (s == NULL)
		return (0);
	i = ft_numbers(nb) - 1;
	s[i + 1] = '\0';
	while (nb >= 10)
	{
		s[i] = nb % 10 + 48;
		nb = nb / 10;
		i--;
	}
	s[i] = nb + 48;
	return (s);
}
