/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 22:39:13 by iaduquen          #+#    #+#             */
/*   Updated: 2019/08/11 23:08:30 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print(int x, char first, char mid, char last)
{
	int i;

	i = 1;
	while (i <= x)
	{
		if (i == 1)
		{
			ft_putchar(first);
			i++;
		}
		else if (i == x)
		{
			ft_putchar(last);
			i++;
		}
		else
		{
			ft_putchar(mid);
			i++;
		}
	}
}

void	rush(int x, int y)
{
	int i;

	i = 1;
	while (i <= y && y > 0 && x > 0)
	{
		if (i == 1)
		{
			ft_print(x, 'A', 'B', 'C');
			i++;
			ft_putchar('\n');
		}
		else if (i == y)
		{
			ft_print(x, 'A', 'B', 'C');
			i++;
			ft_putchar('\n');
		}
		else
		{
			ft_print(x, 'B', ' ', 'B');
			i++;
			ft_putchar('\n');
		}
	}
}
