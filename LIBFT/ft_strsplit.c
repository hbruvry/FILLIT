/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 11:54:36 by hbruvry           #+#    #+#             */
/*   Updated: 2017/12/02 15:53:20 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	**ft_strsplit(char const *s, char c)
{
	size_t	i[3];
	char	**split;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (s == NULL)
		return (NULL);
	split = (char**)malloc((ft_countwords(s, c) + 1) * sizeof(*split));
	if (split == NULL)
		return (NULL);
	while (i[2] < ft_countwords(s, c))
	{
		while (s[i[0]] == c)
			i[0]++;
		while (s[i[0] + i[1]] != c && s[i[0] + i[1]] != '\0')
			i[1]++;
		split[i[2]] = ft_strsub(s, i[0], i[1]);
		i[0] = i[0] + i[1];
		i[1] = 0;
		i[2]++;
	}
	split[i[2]] = NULL;
	return (split);
}
