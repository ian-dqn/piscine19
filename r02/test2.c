/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanco- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:18:13 by hmanco-           #+#    #+#             */
/*   Updated: 2019/08/25 15:35:38 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1000

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/////////////////////////////////////////////////////////

void	ft_tab_char(char *str, char result[32][1000])
{
	int p;
	int w;
	int x;
	int ret;
	int m;
	char buf[BUF_SIZE];

	p = open(str, O_RDONLY);
	if (p == -1)
		write(1, "ERROR\n", 6);
	ret = read(p, buf, BUF_SIZE);
	w = 0;
	while (w < 32)
	{
		x = 0;
		while (buf[m] != '\n')
		{
			if (buf[m] == ' ' && buf[m + 1] == ' ')
			{
				while (buf[m] == ' ')
					m++;
				result[w][x] = ' ';
				x++;
			}
			result[w][x] = buf[m];
			x++;
			m++;
		}
		result[w][x] = '\0';
		while (buf[m] < 48 || buf[m] > 57)
			m++;
		w++;
	}
}

//////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
	int h;
	char result[32][1000];

	h = 0;
	if (argc < 2 || argc > 3)
		write(1, "ERROR\n", 6);
	else if (argc == 2)
	{
		ft_tab_char("text.dict", result);
		while (h < 32)
		{
			printf("%s\n", result[h]);
			h++;
		}
	}
	else if (argc == 3)
	{
		ft_tab_char(argv[1], result);
		//printf("%s\n", result[5]);
		while (h < 32)
		{
			printf("%s\n", result[h]);
			h++;
		}
	}
}













/*
typedef struct s_index
{
	char *number;
	char *value;
} t_index;

void	ft_fill_struct()
{
	char result[32][1000];
	result = ft_tab_char(result);
	int j;

	j = 0;
	while (j < 32)
	{
		printf("%sn", result[j]);
		j++;
	}
}

*/







