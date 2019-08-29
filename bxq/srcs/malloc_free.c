/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 21:50:44 by yocapell          #+#    #+#             */
/*   Updated: 2019/08/28 16:08:02 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	**malloc_tab(int row, int col)
{
	int		i;
	int		j;
	char	**new_tab;

	i = 0;
	j = row + 1;
	if (!(new_tab = ((char**)malloc(sizeof(char*) * (j + 1)))))
		return (0);
	j = col + 1;
	while (i < row)
	{
		if (!(new_tab[i] = ((char*)malloc(sizeof(char) * (j + 1)))))
			return (0);
		i++;
	}
	return (new_tab);
}

void	free_tab(char **tab, int row)
{
	int		i;

	i = 0;
	while (i < row)
	{
		if (!(tab[i]))
			free(tab[i]);
		i++;
	}
	if (!(tab))
		free(tab);
}
