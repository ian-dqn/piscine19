/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 13:45:06 by iaduquen          #+#    #+#             */
/*   Updated: 2019/08/26 08:39:03 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *src, char *dest)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return (dest);
}

char	*ft_strdup(char *src)
{
	char *cpy;

	if (!(cpy = malloc(sizeof(*src) * ft_strlen(src) + 1)))
		return (0);
	ft_strcpy(src, cpy);
	return (cpy);
}
