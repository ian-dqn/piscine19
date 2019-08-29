/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 13:41:07 by iaduquen          #+#    #+#             */
/*   Updated: 2019/08/24 18:01:49 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUF_SIZE 4096
/*
if (buf == ":")
		{
			j = 0;
			while (k < i)
			{
				str_num[j] = buf[k];
				k++;
				j++;
			}
			if (buf == "\n")
			{
				k = i + 1;
			}
			printf("%s", str_num);
		}	
		i++;
*/

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


typedef struct	s_parse
{
	int	num;
	char *str;
}	t_parse;

int main()
{
	int fd;
	int ret;
	char *buf[BUF_SIZE];
	char *str_num = NULL;
	char *num_letter = NULL;
	int on;
	int i = 0;

	on = 1;
//	if (!(buf = malloc (sizeof(buf) * BUF_SIZE + 1)))
//		return (-1);
	fd = open("numbers.dict", O_RDWR, 0666 | O_NONBLOCK);
	if (fd == -1)
		printf("Error Open;\n");
	printf("fd = %d\n", fd);
	while ((ret = read(fd, buf, 1)))
	{
/*		if (ft_strcmp(buf, "\n"))
			on = 1;
		if (ft_strcmp(buf, ":"))
			on = 0;
		if (on == 1)
			str_num = buf;
			ft_strncat(str_num, buf, 1);
		else if (on == 0)
			num_letter = buf;
			ft_strncat(num_letter, buf, 1);
			
*/		printf("%s\t", buf[i]);
	i++;
	}
	printf("num = %s\n letter = %s\n", str_num, num_letter);
	if (close(fd) == -1)
	{
		printf("Error Close;");
		return (1);
	}
	return (0);
}
