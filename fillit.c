/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:52:26 by hbruvry           #+#    #+#             */
/*   Updated: 2017/12/11 17:35:01 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

char	*ft_filecpy(char *file)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	if (fd == 3)
	{
		ret = read(fd, buf, BUF_SIZE);
		buf[ret] = '\0';
		return (ft_strdup(buf));
	}
	if (close(fd) == -1)
		return (NULL);
	return (NULL);
}

size_t	ft_isfilevalid(char *file)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	i = 0;
	j = 0;
	k = 0;
	// check si file contient entre 1 et 26 tetriminos
	l = ft_strlen(file);
	if (l < 8 || 544 < l)
		return (0);
	// check si le nombre de caractere present dans file est coherent
	else if (l % 20 != (l / 20) - 1)
		return (0);
	l = 1;
	while (file[i] != '\0')
	{
		// check si il y a des caractere inconnus
		if (file[i] != '.' && file[i] != '#' &&
			file[i] != '\n' && file[i] != '\0')
			return (0);
		if (l == 21)
		{
			if (j != 4)
				return (0);
			j = 0;
			k = 0;
			l = 0;
		}
		if (l % 5 != 0)
		{
			if (file[i] == '\n')
				return (0);
			if (file[i] == '#')
			{
				if (k > 3)
					return (0);
				k = 0;
				j++;
			}
			if (file[i] == '.' && 0 < j && j < 4)
				k++;
		}
		if (l % 5 == 0 && file[i] != '\n')
			return (0);
		i++;
		l++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	char	*filecpy;

	if (argc == 2)
	{
		filecpy = ft_filecpy(argv[1]);
		if(ft_isfilevalid(filecpy) == 0)
			ft_putstr("error\n");
		else
		{
			ft_putstr("ok\n");
		}
	}
	else
		ft_putstr("error\n");
	return (0);
}
