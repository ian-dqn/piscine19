/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 11:27:13 by iaduquen          #+#    #+#             */
/*   Updated: 2019/08/17 12:57:54 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int **trans_tab(char **str)
{
	int i;
	int j;
	int **tab;

	i = 1;
	j = 0;
	while (str[j])
	{
		if (str[j] >= '0' && str[j] <= '9' && str[j] < 8)
		{
			str[j] = tab[0][i] - '0';
			i++;
			printf("%d", tab[0][i]);
		}
		j++;
		/*
			else if (*str[j] >= '0' && *str[j] <= '9' && *str[j] < 16)
			{
			tab[][]
			}*/
	}

}

int main(int ac, char **av)
{
	trans_tab(&av[1]);
}
