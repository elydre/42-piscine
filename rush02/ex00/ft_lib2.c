/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	free_dict_array(t_dictline *dict)
{
	int	i;

	i = 0;
	while (dict[i].nbr != 0)
	{
		free(dict[i].nbr);
		free(dict[i].str);
		i++;
	}
	free(dict);
}

void	print_dict_array(t_dictline *dict)
{
	int	i;

	i = 0;
	while (dict[i].nbr != 0)
	{
		ft_putstr("'");
		ft_putstr(dict[i].nbr);
		ft_putstr("' : '");
		ft_putstr(dict[i].str);
		ft_putstr("'\n");
		i++;
	}
}

void	*ft_calloc(int count, int size)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(count * size);
	if (ptr == 0)
		return (0);
	while (i < count * size)
		ptr[i++] = 0;
	return (ptr);
}

void	*ft_realloc(void *ptr, int old_size, int new_size)
{
	char	*new_ptr;
	int		i;

	i = 0;
	new_ptr = ft_calloc(new_size, sizeof(char));
	while (i < old_size)
	{
		new_ptr[i] = ((char *)ptr)[i];
		i++;
	}
	free(ptr);
	return (new_ptr);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
