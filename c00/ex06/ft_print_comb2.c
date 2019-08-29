/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 12:24:42 by iaduquen          #+#    #+#             */
/*   Updated: 2019/08/11 20:24:11 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int nb)
{
	int n;

	n = nb / 10;
	ft_putchar(n + '0');
	n = nb % 10;
	ft_putchar(n + '0');
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 1;
	b = 0;
	while (b <= 98)
	{
		while (a <= 99)
		{
			ft_print(b);
			ft_putchar(' ');
			ft_print(a);
			if (b < 98)
				write(1, ", ", 2);
			a++;
		}
		b++;
		a = b + 1;
	}
}

int main()
{
	ft_print_comb2();
}
