/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:35:24 by hbruvry           #+#    #+#             */
/*   Updated: 2017/12/03 10:15:51 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdio.h>

static	size_t	ft_itoalen(int n)
{
	size_t i;

	i = 0;
	if (n == 0)
		i++;
	else if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	size_t	i;
	char	*itoa;

	i = ft_itoalen(n);
	itoa = (char*)malloc((i + 1) * sizeof(char));
	if (itoa == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		itoa[0] = '-';
		n = n * -1;
	}
	itoa[i] = '\0';
	while (n > 0)
	{
		itoa[i - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (itoa);
}
