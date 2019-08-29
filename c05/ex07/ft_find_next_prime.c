/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 22:38:01 by iaduquen          #+#    #+#             */
/*   Updated: 2019/08/26 01:46:16 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_prime(int nb)
{
	int n;

	n = 3;
	if (nb <= 2)
		return (2);
	if (nb % 2 == 0)
		nb++;
	while (n <= nb / n)
	{
		if (nb % n == 0)
			return (0);
		n += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (nb % 2 == 0)
		ft_find_prime(nb++);
	while (!ft_find_prime(nb))
		nb += 2;
	return (nb);
}
