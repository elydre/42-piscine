/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*read_file(char *file_path)
{
	char	*str;
	int		len;
	int		fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (0);
	len = get_file_len(file_path);
	str = malloc(len + 1);
	read(fd, str, len);
	str[len] = '\0';
	close(fd);
	return (str);
}

void	get_first_line(t_map *map, char *buffer)
{
	int	size;

	size = ft_line_len(buffer);
	map->nb_l = ft_atoin(buffer, size - 3);
	map->empty = buffer[size - 3];
	map->obstacle = buffer[size - 2];
	map->full = buffer[size - 1];
}

void	get_map_len(t_map *map, char *buffer)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	i++;
	while (buffer[i + len] && buffer[i + len] != '\n')
		len++;
	map->nb_c = len;
}

void	get_map(t_map *map, char *buffer)
{
	int	i;
	int	l;
	int	c;

	i = 0;
	l = 0;
	c = 0;
	while (buffer && *buffer != '\n')
		buffer++;
	buffer++;
	while (buffer[i])
	{
		if (buffer[i] != '\n')
		{
			map->map[l][c] = (buffer[i] == map->empty);
			if (c < map->nb_c - 1)
				c++;
			else
			{
				c = 0;
				l++;
			}
		}
		i++;
	}
}

t_map	*read_map(char *filepath)
{
	char	*buffer;
	t_map	*map;

	map = NULL;
	if (filepath == NULL)
		buffer = read_stdin();
	else
		buffer = read_file(filepath);
	if (!buffer)
		return (NULL);
	map = ft_struct_malloc(map);
	if (check_min_line(buffer))
		return (dual_free(map, buffer));
	get_first_line(map, buffer);
	if (check_first_line(map) || check_consistency(map, buffer))
		return (dual_free(map, buffer));
	get_map_len(map, buffer);
	if (check_line(map, buffer))
		return (dual_free(map, buffer));
	ft_map_malloc(map);
	get_map(map, buffer);
	free(buffer);
	return (map);
}
