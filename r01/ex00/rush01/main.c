/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 10:52:25 by qupousse          #+#    #+#             */
/*   Updated: 2019/08/18 21:25:59 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	enter_digits(int **tab, int i, int j, int digits);

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		ft_check_line(int i, int **tab)
{
	int j;
	int k;

	j = 1;
	k = j + 1;
	while (i < 4)
	{
		while (k < 5)
		{
			if (tab[i][j] == tab[i][k])
				return (0);
			k++;
		}
		j++;
		k = j + 1;
	}
	k = 0;
	j = 1;
	while (j < 5)
	{
		k += tab[i][j];
		j++;
	}
	if (k != 10)
		return (0);
	return (1);
}

void	ft_print_tab(int **tab, int size)
{
	int i;
	int j;
	char nbr;

	i = 0;
	j = 0;
	if (size == 6)
	{
		while (i < 6)
		{
			while (j < 6)
			{
				nbr = tab[i][j] + 48;
				if (j == 5)
					write(1, &nbr, 1);
				else
				{
					write(1, &nbr, 1);
					write(1, " ", 1);
				}
				j++;
			}
			j = 0;
			i++;
			write(1, "\n", 1);
		}
	}
	else if (size == 4)
	{
		i = 1;
		j = 1;
		while (i < 5)
		{
			while (j < 5)
			{
				nbr = tab[i][j] + 48;
				if (j == 4)
					write(1, &nbr, 1);
				else
				{
					write(1, &nbr, 1);
					write(1, " ", 1);
				}
				j++;
			}
			j = 1;
			i++;
			write(1, "\n", 1);
		}
	}
}

void	ft_fill_empty_tab(int **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 6)
	{
		while (j < 6)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
		j = 0;
	}
}

int		ft_fill_tab(int **tab, char *str)
{
	int i;
	int j;
	int k;
	int l;
	char temp;

	i = 0;
	j = 1;
	k = 0;
	while (k < 16)
	{
		if (str[l] == 32)
		{
			temp = str[l];
			l++;
		}
		else if (str[l] >= 49 && str[l] <= 52)
		{
			temp = str[l];
			tab[i][j] = (int)(str[l] - 48);
			l++;
			j++;
			k++;
		}
		else
		{
			printf("else first occurence\n");
			return (0);
		}
		while (j < 5)
		{
			if (str[l] == 32 && temp >= 49 && temp <= 52)
			{
				temp =  str[l];
				l++;	
			}
			else if (str[l] >= 49 && str[l] <= 52 && temp == 32)
			{
				temp = str[l];
				tab[i][j] = (int)(str[l] - 48);
				l++;
				k++;
				j++;
			}
			else
			{
				printf("else first line\n");
				return (0);
			}
		}
		i = 5;
		j = 1;
		while (j < 5)
		{
			if (str[l] == 32 && (temp >= 49 && temp <= 52))
			{
				temp =  str[l];
				l++;
			}
			else if (str[l] >= 49 && str[l] <= 52 && temp == 32)
			{
				temp = str[l];
				tab[i][j] = (int)(str[l] - 48);
				l++;
				k++;
				j++;
			}
			else
			{
				printf("else last line\n");
				return (0);
			}
		}
		j = 0;
		i = 1;
		while (i < 5)
		{
			if (str[l] == 32 && (temp >= 49 && temp <= 52))
			{
				temp =  str[l];
				l++;	
			}
			else if (str[l] >= 49 && str[l] <= 52 && temp == 32)
			{
				temp = str[l];
				tab[i][j] = (int)(str[l] - 48);
				l++;
				k++;
				i++;
			}
			else
			{
				printf("else first col\n");
				return (0);
			}
		}
		i = 1;
		j = 5;
		while (i < 5)
		{
			if (str[l] == 32 && (temp >= 49 && temp <= 52))
			{
				temp =  str[l];
				l++;	
			}
			else if (str[l] >= 49 && str[l] <= 52 && temp == 32)
			{
				temp = str[l];
				tab[i][j] = (int)(str[l] - 48);
				l++;
				k++;
				i++;
			}
			else
			{
				printf("else last col\n");
				return (0);
			}
		}
	}
	return (1);	
}

int 	ft_solution(int **tab, int i, int j)
{
	if (tab[i-1][j] == 4 && tab[i][j-1] == 4)
	{
		if (tab[i+4][j] == 1)
		{
			while (i < 5)
			{
				tab[i][j] = i;
				i++;
			}
		}
		i = 1;
	}
	return (1);
}

void	ft_free(int **tab)
{
	int i;

	i = 0;
	while (i < 6)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int 	main(int argc, char *argv[])
{
	int **tab;
	int i;
	int j;

	i = 0;
	j = 0;
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	if (!(tab = (int**)malloc(6 * sizeof(int*))))
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	while (i < 6)
	{
		if (!(tab[i] = (int*)malloc(6 * sizeof(int))))
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	ft_fill_empty_tab(tab);
	if (ft_fill_tab(tab, argv[1]) == 0)
	{
		printf("fill_tab error\n");
		write(1, "Error\n", 6);
		return (-1);
	}
//	if (check() == 1)
//		enter_digits(tab, i, j);
//	ft_solution(tab, 1, 1);
	ft_print_tab(tab, 6);
	enter_digits(tab, 0, 0, 1);
//	if (enter_digits(tab, i, j) == 1)
//		ft_print_tab(tab, 4);
	ft_free(tab);
	return (0);
}
