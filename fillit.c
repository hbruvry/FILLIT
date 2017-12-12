/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:52:26 by hbruvry           #+#    #+#             */
/*   Updated: 2017/12/12 17:38:13 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"
#include <stdio.h>

char	***ft_filetotab(char *file)
{
	int		i;
	int		fd;
	char	buf[BUF_SIZE + 1];
	char	***tab;

	i = 0;
	// J'ouvre le fichier une premiere fois
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	// J'estime le nombre de tetriminos
	while (read(fd, buf, BUF_SIZE) > 0)
		i++;
	printf("Tetriminos == %d\n\n", i);
	// Je malloc un tableau ^3
	tab = (char***)malloc((i + 1) * sizeof(**tab));
	if (tab == NULL)
		return (0);
	tab[i] = NULL;
	// Je reset mon buf
	close(fd);
	fd = open(file, O_RDONLY);
	i = 0;
	// Je remplis mon tableau ^3
	while (read(fd, buf, BUF_SIZE) > 0)
		tab[i++] = ft_strsplit(buf, '\n');
	close(fd);
	// Je retourne mon tableau ^3
	return (tab);
}

int		ft_checktab(char ***tab)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			while (tab[i][j][k])
			{
				// Check si le char est bon
				if (tab[i][j][k] != '.' && tab[i][j][k] != '#')
					return (1);
				k++;
			}
			// Check si la longueur du tableau est bonne
			if (k != 4)
				return (1);
			k = 0;
			j++;
		}
		// Check si la longueur du tableau ^2 est bonne
		if (j != 4)
			return (1);
		// Check si la longuer du tableau ^3 est bonne
		if (i > 26)
			return (1);
		j = 0;
		i++;
	}
	return (0);
}

int		ft_displaytab(char ***tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		ft_putstr("Tetri ");
		ft_putnbr(i);
		ft_putstr("\n");
		while (tab[i][j])
		{
			ft_putchar('	');
			ft_putnbr(j);
			ft_putchar(' ');
			ft_putstr(tab[i][j]);
			ft_putchar('\n');
			j++;
		}
		ft_putstr("\n");
		j = 0;
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char	***tetriminos;

	if (argc == 2)
	{
		tetriminos = ft_filetotab(argv[1]);
		ft_displaytab(tetriminos);
		if (ft_checktab(tetriminos))
			ft_putstr("error\n");
	}
	else
		ft_putstr("error\n");
	return (0);
}
