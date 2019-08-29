/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 11:05:48 by iaduquen          #+#    #+#             */
/*   Updated: 2019/08/15 22:18:27 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_alpha(char str)
{
	if (!(str >= 'A' && str <= 'Z') && !(str >= 'a' && str
				<= 'z') && !(str >= '0' && str <= '9'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 1;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') && (check_alpha(str[i - 1]) == 1))
			str[i] -= 32;
		i++;
	}
	return (str);
}
