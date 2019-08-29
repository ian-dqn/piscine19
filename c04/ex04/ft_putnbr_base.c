/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 18:48:36 by iaduquen          #+#    #+#             */
/*   Updated: 2019/08/19 20:42:41 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		check_base(char *str, int i, int j)
{
	if (str[j] == '-' || str[j] == '+')
		return (0);
	if (str[j] < 32 || str[j] > 126)
		return (0);
	if (str[i] == str[j])
		return (0);
	return (1);
}

int		loop(char *str)
{
	int i;
	int j;

	i = -1;
	while (str[++i])
	{
		j = i + 1;
		while (str[++j])
		{
			if (check_base(str, i, j) == 0)
				return (0);
		}
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int a;

	a = ft_strlen(base);
	if (loop(base) == 0 || a == 0 || a == 1)
		base = 0;
	else
	{
		if (nbr < 0)
		{
			nbr *= -1;
			ft_putchar('-');
		}
		if (nbr > a)
		{
			ft_putnbr_base(nbr / a, base);
			ft_putnbr_base(nbr % a, base);
		}
		else
			ft_putchar(base[nbr]);
	}
}
