/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:01:24 by iaduquen          #+#    #+#             */
/*   Updated: 2019/08/18 18:22:03 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	tn_check(int *row, int *col)
{
	if (col[1] + col[2] + col[3] + col[4] != 10)
		return (0);
	else if (row[1] + row[2] + row[3] + row[4] != 10)
		return (0);
	else
		return (1);
}

int	**tn_enter(int **tab)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (i < 5)
	{
		if (tab[0][i] == 4)
		{
			tab[1][i] = 1;
			tab[2][i] = 2;
			tab[3][i] = 3;
			tab[4][i] = 4;
		}
		i++;
	}
	while (i < 5)
	{
		if (tab[6][i] == 4)
		{
			tab[4][i] = 1;
			tab[3][i] = 2;
			tab[2][i] = 3;
			tab[1][i] = 4;
		}
		i++;
	}

	while (i < 5)
	{
		if (tab[i][0] == 4)
		{
			tab[i][1] = 1;
			tab[i][2] = 2;
			tab[i][3] = 3;
			tab[i][4] = 4;
		}
		i++;
	}
	while (j < 5)
	{
		if (tab[i][6] == 4)
		{
			tab[i][4] = 1;
			tab[i][3] = 2;
			tab[i][2] = 3;
			tab[i][1] = 4;
		}
		i++;
	}
	return (tab);
}

int main()
{
	int **tab={
		{0,4,3,2,1,0},
		{4,0,0,0,0,1},
		{3,0,0,0,0,2},
		{2,0,0,0,0,2},
		{1,0,0,0,0,2},
		{0,1,2,2,2,0}
	};
	tn_enter(tab);
	int i = 0;
	int j = 0;
	while (i < 5)
	{
		while (j < 5)
		{
			printf("%d", tab[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
}
