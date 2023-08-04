/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	s;
	unsigned int	i;

	s = 0;
	i = 0;
	while (src[s] != '\0')
		s++;
	if (size == 0)
		return (s);
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (s);
}

/*
#include <stdio.h>

int main()
{
	char src[] = "Hello";
	char dest[] = "Bonjour";
	unsigned int size = 3;
	printf("%d\n", ft_strlcpy(dest, src, size));
	printf("%s\n", dest);
	return (0);
}
*/
