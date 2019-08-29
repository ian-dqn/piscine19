/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 19:13:17 by iaduquen          #+#    #+#             */
/*   Updated: 2019/08/21 20:22:34 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		i;
	char	*temp;

	i = 1;
	while (++i < ac)
	{
		if (ft_strcmp(av[i - 1], av[i]) > 0)
		{
			temp = av[i - 1];
			av[i - 1] = av[i];
			av[i] = temp;
			i = 1;
		}
	}
	i = 1;
	while (++i < ac)
	{
		ft_putstr(av[i]);
		ft_putstr("\n");
	}
	return (0);
}
