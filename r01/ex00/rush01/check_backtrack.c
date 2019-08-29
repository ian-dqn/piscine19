/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_backtrack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 11:21:05 by iaduquen          #+#    #+#             */
/*   Updated: 2019/08/18 21:30:09 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


/*
int	in_col(int **tab, int i, int j, int digits)
{
	while (++i < 5)
	{
		if (tab[i][j] == digits)
			return (0);
	}
	return (1);
}

int	in_line(int **tab, int i, int j, int digits)
{
	while (++j < 5)
	{
		if (tab[i][j] == digits)
			return (0);
	}
	return (1);
}
*/
int is_empty(int **tab, int i, int j)
{
//	printf("i=%d  j=%d\n", i, j);
	if (tab[i][j] == 0)
		return (1);
	return (0);
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
	while (--j > 0 && j < 5)
	{
//		printf("j=%d\n", j);
		if (tab[i][j] > indiceb)
		{
			indiceb = tab[i][j];
			tailleb++;
			printf("indiceb=%d, tailleb=%d, tab[%d][%d]=%d\n", indiceb, tailleb, i, j, tab[i][j]);
		}

	}
	while (++j < 5)
	{
		if (tab[i][j] > indicea)
		{
			indicea = tab[i][j];
			taillea++;
//			printf("indicea=%d, taillea=%d, tab[%d][%d]=%d\n", indicea, taillea, i, j, tab[i][j]);
		}
	}
	printf("tab[%d][0]=%d, tab[%d][6]=%d\n", i, tab[i][0], i, tab[i][5]);
	if (taillea == tab[i][0] && tailleb == tab[i][5])
	{
		printf("j == %d\n", j);
		return (1);
	}

	return (0);
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
	if (taillea == tab[0][j] && tailleb == tab[6][j])
		return (1);
	return (0);
}
int check_equal_row(int **tab, int j)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (++k < 5)
	{
		printf("your in\n");
		while (++i < 5)
		{
			if (tab[k][j] == tab[i][j])
				return (0);
		}
	}
	return (1);
}

int check_equal_line(int **tab, int i)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while(++k < 5)
	{	
		while (++j < 5)
		{
			if (tab[i][k] == tab[i][j])
				return (0);
		}
		j = 0;
	}
	return (1);
}
/*
int check_around(int **tab, int i, int j)
{
	if (tab[i][j] == )
}
*/
int	enter_digits(int **tab, int i, int j, int digits)
{
	if (i == 5 && j == 5)
		return (1);
	while (++j < 5 && digits <= 4)
	{
		while (++i < 5 && digits <= 4)
		{
			printf("i=%d  j=%d\n", i, j);
			if (is_empty(tab, i, j) == 1)
			{
				tab[i][j] = digits;
				if (i > 1 && j > 1)
				{
					if (tab[i][j] == tab[i][j - 1] || tab[i][j] != tab[i - 1][j])
					{
						tab[i][j] = 0;
						enter_digits(tab, i, j, digits++);
					}
					//			printf("dig=%d, tab[%d][%d]=%d\n", digits, i, j, tab[i][j]);
					//				if (enter_digits(tab, i, j) == 1)
					//					return (1);
				}
			}
		}
	}
			if (check_row(tab, i, j) == 0 && check_equal_row(tab, i) == 0)
			{
				//			tab[i][j--] = 0;
				ft_print_tab(tab, 6);
				return (0);
			}
			//		else
			//			enter_digits(tab, i--, 0, digits++);

	//		if (check_col(tab, i, j) == 0 && check_equal_line(tab, j == 0))
	//			tab[i][j] = 0;
	//		return (0);
	return (0);
}
