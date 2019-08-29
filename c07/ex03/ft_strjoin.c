/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 08:51:59 by iaduquen          #+#    #+#             */
/*   Updated: 2019/08/27 19:31:58 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_ultimate_strlen(int size, char **strs, char *sep)
{
	int i;
	int j;
	int k;
	int l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	while (size > 0)
	{
		while (strs[i][j])
		{
			j++;
		}
		l += j;
		i++;
		j = 0;
		size--;
	}
	while (sep[k])
		k++;
	k *= (i - 1);
	l += k;
	return (l);
}

char		*ft_strcat(char *dest, char *src)
{
	int i;

	i = 0;
	while (dest[i])
		i++;
	while (*src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = 0;
	return (dest);
}

char		*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;
	int		a;

	if (size <= 0 || !strs || !*strs)
	{
		tab = (char*)malloc(sizeof(char));
		tab[0] = 0;
		return (tab);
	}
	a = ft_ultimate_strlen(size, strs, sep);
	if (!(tab = (char*)malloc(sizeof(char) * (a + 1))))
		return (0);
	tab[0] = 0;
	while (--size > 0)
	{
		if (!*strs)
			*strs = 0;
		ft_strcat(tab, *strs);
		ft_strcat(tab, sep);
		strs++;
	}
	ft_strcat(tab, *strs);
	return (tab);
}
