/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	c;
	int	d;

	c = 0;
	d = 0;
	while (dest[c] != '\0')
		c++;
	while (src[d] != '\0')
	{
		dest[c] = src[d];
		c++;
		d++;
	}
	dest[c] = '\0';
	return (dest);
}

int	calc_total_len(int size, char **strs, char *sep)
{
	int	total_len;
	int	i;

	total_len = 0;
	i = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		i++;
	}
	total_len += ft_strlen(sep) * (size - 1);
	return (total_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	int		total_len;
	int		i;

	if (size == 0)
	{
		ret = malloc(sizeof(char));
		ret[0] = '\0';
		return (ret);
	}
	total_len = calc_total_len(size, strs, sep);
	ret = malloc(sizeof(char) * (total_len + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	ret[0] = '\0';
	while (i < size)
	{
		ft_strcat(ret, strs[i]);
		if (i < size - 1)
			ft_strcat(ret, sep);
		i++;
	}
	return (ret);
}

/*
#include <stdio.h>

int main(void)
{
	char *strs[4] = {"Hello", "World", "!", "!"};
	char *sep = " - ";
	char *ret;

	ret = ft_strjoin(4, strs, sep);
	printf("%s\n", ret);
	free(ret);
	return (0);
}
*/
