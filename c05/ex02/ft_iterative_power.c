/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 22:58:45 by iaduquen          #+#    #+#             */
/*   Updated: 2019/08/22 12:15:20 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int a;

	a = 1;
	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	else if (nb == 0)
		return (0);
	while (power > 0)
	{
		a *= nb;
		power--;
	}
	return (a);
}
