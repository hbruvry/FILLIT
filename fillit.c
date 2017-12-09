/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:52:26 by hbruvry           #+#    #+#             */
/*   Updated: 2017/12/09 18:59:46 by hbruvry          ###   ########.fr       */
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

	i = 0;
	if (ft_strlen(file) > 544 || file == NULL)
		return (0);
	while (file[i] != '\0')
	{
		if (file[i] != '.' && file[i] != '#' &&
			file[i] != '\n' && file[i] != '\0')
			return (0);
		i++;
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
			ft_putstr("error");
		else
			ft_putstr(filecpy);
	}
	else
		ft_putstr("error");
	return (0);
}
