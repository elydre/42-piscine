/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

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

t_map	*ft_struct_malloc(t_map *map)
{
	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	return (map);
}

void	ft_map_malloc(t_map *map)
{
	int	i;

	i = 0;
	map->map = malloc(sizeof(int *) * map->nb_l);
	while (i < map->nb_l)
	{
		map->map[i] = malloc(sizeof(int) * map->nb_c);
		i++;
	}
}

void	*ft_realloc(void *ptr, unsigned long long old_size,
					unsigned long long new_size)
{
	char					*new_ptr;
	unsigned long long		i;

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

t_arg	*free_and_ret(t_arg *arg)
{
	free(arg->files);
	free(arg);
	return (NULL);
}
