/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:25:11 by iaduquen          #+#    #+#             */
/*   Updated: 2019/08/17 20:17:45 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	a;
	char	b;
	char	*base_hex;

	base_hex = "0123456789abcdef";
	i = -1;
	while (str[++i])
	{
		if (str[i] < 32 || str[i] > 126)
		{
			a = str[i] / 16;
			b = str[i] % 16;
			ft_putchar(92);
			ft_putchar((base_hex[a]));
			ft_putchar((base_hex[b]));
		}
		else
			ft_putchar(str[i]);
	}
}
