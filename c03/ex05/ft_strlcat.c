/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 12:41:06 by iaduquen          #+#    #+#             */
/*   Updated: 2019/08/20 11:35:55 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int a;
	unsigned int i;
	unsigned int j;
	unsigned int b;

	i = 0;
	j = 0;
	if (size == 0)
		return (size + b);
	b = ft_strlen(src);
	a = ft_strlen(dest);
	if (size < b)
		return (b + size);
	else
	{
		while (src[j] && i < size)
		{
			dest[a] = src[j];
			a++;
			j++;
		}
		dest[j] = 0;
		return (a + b);
	}
}
