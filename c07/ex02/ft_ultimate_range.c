/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:04:03 by iaduquen          #+#    #+#             */
/*   Updated: 2019/08/27 18:54:14 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int *tab;
	int i;

	i = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	if (!(tab = (malloc(sizeof(**range) * (max - min) + 1))))
		return (-1);
	while (max > min)
	{
		tab[i] = min;
		i++;
		min++;
	}
	*range = tab;
	return (i);
}
