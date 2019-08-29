/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:08:53 by yocapell          #+#    #+#             */
/*   Updated: 2019/08/28 21:47:21 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>
#include <stdlib.h>

int		check_first_line(char *tab, t_char *init)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (tab[i] >= '0' && tab[i] <= '9')
	{
		while (tab[i] >= '0' && tab[i] <= '9')
		{
			i++;
		}
		if ((i > 0 && (tab[i] >= 32 && tab[i] <= 126)
					&& (tab[i + 1] >= 32 && tab[i + 1] <= 126)
					&& (tab[i + 2] >= 32 && tab[i + 2] <= 126)
					&& tab[i + 3] == '\0'))
		{
			init->vide = tab[i];
			init->obstacle = tab[i + 1];
			init->plein = tab[i + 2];
			return (1);
		}
	}
	return (0);
}

int		check_other_lines(char *tab, t_char init)
{
	int		i;

	i = 0;
	while (tab[i] != '\0')
	{
		if (!(tab[i] == init.vide || tab[i] == init.obstacle))
			return (0);
		i++;
	}
	return (1);
}

int		check_input(char **tab, int size)
{
	int		i;
	t_char	init;

	i = 0;
	if (check_first_line(tab[0], &init))
	{
		while (++i < size)
		{
			if (!(check_other_lines(tab[i], init)))
				return (0);
		}
	}
	return (1);
}
