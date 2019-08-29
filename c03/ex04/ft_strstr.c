/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 11:05:32 by iaduquen          #+#    #+#             */
/*   Updated: 2019/08/20 11:31:20 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;

	i = 0;
	if (*to_find == 0)
		return (str);
	while (*str)
	{
		i = 0;
		while (to_find[i] && str[i] == to_find[i])
		{
			i++;
			if (to_find[i] == 0)
				return (str);
		}
		str++;
	}
	return (0);
}
