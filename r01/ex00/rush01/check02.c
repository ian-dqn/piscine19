/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:56:16 by iaduquen          #+#    #+#             */
/*   Updated: 2019/08/17 19:53:08 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_10(int *row, int *col)
{
	if (col[1] + col[2] + col[3] + col[4] != 10)
		return (0);
	else if (row[1] + row[2] + row[3] + row[4] != 10)
		return (0);
	else
		return (1);
}

int check(int *tab)
{
	while (i <= 5)
	{
		while (j <= 5)
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
}
