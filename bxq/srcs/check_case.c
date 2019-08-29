/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 04:50:15 by yocapell          #+#    #+#             */
/*   Updated: 2019/08/28 22:00:40 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	check_is_one(char **tab, int x, int y, t_char init)
{
	if ((x || y) == 0)
	{
		tab[x][y] = '1';
		return ('1');
	}
	else if (((tab[x - 1][y] == 1 && tab[x][y - 1] == 1)
		&& tab[x - 1][y - 1] == init.obstacle))
	{
		tab[x][y] = '1';
		return ('1');
	}
	else if ((tab[x - 1][y] || tab[x][y - 1]) == init.obstacle)
	{
		tab[x][y] = '1';
		return ('1');
	}
	return (0);
}

char	what_is_cell(char **tab, int x, int y, t_char init)
{
	if (tab[x][y] != init.obstacle)
	{
		if (tab[x - 1][y] <= tab[x][y - 1])
		{
			tab[x][y] = (tab[x - 1][y] + 1);
			return (tab[x][y]);
		}
		else
		{
			tab[x][y] = (tab[x][y - 1] + 1);
			return (tab[x][y]);
		}
	}
	return (0);
}

void	is_greater(t_biggest_sqr *sqr, char **tab, int x, int y)
{
	if (sqr->value < tab[x][y])
	{
		sqr->x = x;
		sqr->y = y;
		sqr->value = tab[x][y];
	}
}

char	check_cell(char **tab, int x, int y, t_char init)
{
	if (check_is_one(tab, x, y, init))
		return ('1');
	else
		return (what_is_cell(tab, x, y, init));
}
