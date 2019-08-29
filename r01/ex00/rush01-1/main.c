/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 10:52:25 by qupousse          #+#    #+#             */
/*   Updated: 2019/08/18 20:20:42 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

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

void	ft_print_tab(int **tab)
{
	int i;
	int j;
	int nbr;

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
	l = 0;
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
			return (0);
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
				return (0);
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
				return (0);
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
				return (0);
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
				return (0);
		}
	}
	return (1);	
}

int check_row(int **tab, int i, int j)
{
	int indicea;
	int indiceb;
	int taillea;
	int tailleb;

	indicea = 0;
	indiceb = 0;
	taillea = 0;
	tailleb = 0;
	while (--j > 0 && j < 6)
	{

		if (tab[i][j] > indiceb)
		{
			indiceb = tab[i][j];
			tailleb++;
		}
	}
	while (++j < 5)
	{
		if (tab[i][j] > indicea)
		{
			indicea = tab[i][j];
			taillea++;
		}
	}
	if (taillea <= tab[i][0] && tailleb <= tab[i][5])
	{
		return (1);
	}
	return (0);
}

int 	ft_possible(int **tab, int i, int j, int k)
{
	int start_i;
	int result;
	int start_j;

	result = k;
	start_i = 1;
	start_j = 1;
	if (result < 4)
	{
		while (start_i < 5 && start_j < 5 && (tab[start_i][j] != 0 || tab[i][start_j] != 0))
		{
			if (tab[start_i][j] == result || tab[i][start_j] == result)
			{
				result += 1;
				result = ft_possible(tab, i, j, result);
			}
			start_j++;
			start_i++;
		}
	}
	return result;
}

int check_col(int **tab, int i, int j)
{
	int indicea;
	int indiceb;
	int taillea;
	int tailleb;

	indicea = 0;
	indiceb = 0;
	taillea = 0;
	tailleb = 0;

	while (--i > 0 && i < 5)
	{
		printf("inb %d tai%dbtab[%d][%d]=%d",indiceb,taiilleb  i, j tab[i][j]);
		if (tab[i][j] > indiceb)
		{
			indiceb = tab[i][j];
			tailleb++;
		}
	}
	while (++i < 5)
	{
		if (tab[i][j] > indicea)
		{
			indicea = tab[i][j];
			taillea++;
		}
	}
	if (taillea <= tab[i][0] && tailleb <= tab[i][5])
	{
		return (1);
	}
	return (0);
}

void	ft_generate_line(int **tab, int i, int j)
{	
	if (j < 5)
	{
		int t = ft_possible(tab, i, j, 1);
		tab[i][j] = t;
/*		if (i != 4 || j != 4)
		{
			if (!(check_row(tab, i, j) == 1))
				ft_generate_line(tab, i, j);
			//if (!(check_col(tab, i, j) == 1))
			//	ft_generate_line(tab, i, j);
		}		*/
		ft_generate_line(tab, i, ++j);	
	}
}


int 	ft_solution(int **tab, int i, int j)
{
	while (i < 5)
	{
		ft_generate_line(tab,  i, j);
		i++;
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

	i = 0;
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
		write(1, "Error\n", 6);
		return (-1);
	}
	ft_solution(tab, 1, 1);
	ft_print_tab(tab);
	ft_free(tab);
	return (0);
}
