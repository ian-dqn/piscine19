/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <iaduquen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 21:27:50 by iaduquen          #+#    #+#             */
/*   Updated: 2019/08/28 22:18:28 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 1
#include "../includes/bsq.h"

void	free_tab(char **tab, int row);
char	**malloc_tab(int row, int col);

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_open(void)
{
	int fd;

	if(!(fd = open("map.txt", O_RDONLY)))
	{
		ft_putstr("ERROR open\n");
		exit(0);
	}
	fprintf(stderr, "open\n");
	return (fd);
}

int	ft_close(int fd)
{
	if (close(fd) == -1)
	{
		ft_putstr("Error Close;");
		return (0);
	}
	fprintf(stderr, "close\n");
	return (1);
}

void	ft_end_line(t_check_read *compt)
{
	if ((compt->tmp != compt->nb_col) && compt->nb_line > 1 )
	{
		ft_putstr("map error\n");
		exit(0);
	}
	compt->tmp = compt->nb_col;
	compt->nb_col = 0;
	compt->nb_line++;
}

void	ft_read_dyn(int fd, t_check_read *compt)
{
	int ret;
	char buf[BUF_SIZE + 1];

	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		compt->nb_col++;
		compt->nb_tot++;
		if (*buf == '\n')
			ft_end_line(compt);
	}
	buf[ret] = '\0';
	compt->nb_col = compt->tmp;
}

char	*malloc_simple(t_check_read *compt)
{
	char *buf;

	if(!(buf = (char*)malloc(sizeof(char *) * compt->nb_tot + 1)))
		return (0);
	return (buf);
}

char **ft_file_to_strs(int fd, t_check_read *compt)
{
	char *buf;
	int ret;
	char **strs;
	int tab[3];

	tab[0] = 1;
	tab[1] = 0;
	tab[2] = 1;
	buf = malloc_simple(compt);
	strs = malloc_tab(compt->nb_line, compt->nb_col);
	ret = read(fd, buf, compt->nb_tot);
	while (++tab[0] < compt->nb_line)
	{
		while (++tab[1] < compt->nb_col)
		{
			strs[tab[0]][tab[1]] = buf[++tab[2]];
			tab[1]++;
			tab[2]++;
				ft_putstr(buf);
		}
		strs[tab[0]][tab[1]] = 0;
		tab[2]++;
	}
	return (strs);
}

char	**file_to_strs(int fd, t_check_read *compt)
{
	char **strs;

	strs = ft_malloc_tab(compt->nb_line, compt->nb_col)
	strs = 0;
	while (*buf)
		strs = buf;
	return (strs)
}


int main(void)
{
	t_check_read compt;
	int fd;
	char **strs;

	compt.nb_col = 0;
	compt.nb_line = 0;
	compt.tmp = 0;
	compt.nb_tot = 0;
	fd = ft_open();
	ft_read_dyn(fd, &compt);
	ft_close(fd);
	ft_free(strs, compt->nb_row);
	return (0);
}

char	**ft_read_line(int fd, t_check_read *compt)
{
	int tab[3];
	int ret;
	char *buf;
	char **strs;

	tab[0] = -1;
	tab[1] = -1;
	tab[2] = 0;
	buf = malloc_simple(compt);
	strs = malloc_tab(compt->nb_line, compt->nb_col);
	while ((ret = read(fd, buf, compt->nb_col)))
	{
		while (*buf != '\n')
		{
			buf[ret] = 0;
			strs[tab[0]][++tab[1]] = buf[tab[2]];
		}
		strs[tab[0]][tab[1]] = 0;
		tab[1] = 0;
	}
	return (strs);
}
