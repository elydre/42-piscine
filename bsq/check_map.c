/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_consistency(t_map *map, char *buffer)
{
	int	i;
	int	count;

	i = 0;
	count = -1;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			count++;
		i++;
	}
	if (count == map->nb_l)
		return (0);
	else
		return (1);
}

int	check_min_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	i++;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_char(t_map *map, char c)
{
	if (c >= 32 && c <= 126)
	{
		if (c == map->empty || c == map->obstacle)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int	check_line(t_map *map, char *buffer)
{
	unsigned int	char_count;
	int				i;

	i = 0;
	char_count = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	i++;
	while (buffer[i])
	{
		if (is_valid_char(map, buffer[i]))
			char_count++;
		else if (buffer[i] == '\n' && (char_count == (unsigned int)map->nb_c))
			char_count = 0;
		else
			return (1);
		i++;
	}
	return (0);
}

int	check_first_line(t_map *map)
{
	if (map->nb_l < 1)
		return (1);
	else if (map->obstacle == map->empty
		|| map->obstacle == map->full
		|| map->empty == map->full)
		return (1);
	else
		return (0);
}
