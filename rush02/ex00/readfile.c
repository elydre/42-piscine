/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*read_file(char *file_path)
{
	int		fd;
	int		ret;
	char	buf[100];
	char	*str;
	int		str_len;

	fd = open(file_path, O_RDONLY);
	str = ft_calloc(1, sizeof(char));
	str_len = 0;
	if (fd == -1)
		return (0);
	ret = read(fd, buf, 99);
	while (ret > 0)
	{
		buf[ret] = '\0';
		str = ft_realloc(str, str_len, str_len + ret + 1);
		ft_strcat(str, buf);
		str_len += ret;
		ret = read(fd, buf, 99);
	}
	close(fd);
	return (str);
}

int	patch_spaces(char *str, int i)
{
	while ((str[i] == ' ' || str[i] == '\n') && i >= 0)
		i--;
	return (i + 1);
}

t_parse_points	gen_points(char *file_str, int i)
{
	t_parse_points	points;

	while (file_str[i] == ' ')
		i++;
	points.nbr_start = i;
	while (file_str[i] >= '0' && file_str[i] <= '9')
		i++;
	points.nbr_end = i;
	while (file_str[i] == ' ')
		i++;
	if (file_str[i] == ':')
		i++;
	else
	{
		ft_putstr("Dict Error\n");
		points.nbr_end = -1;
		return (points);
	}
	while (file_str[i] == ' ')
		i++;
	points.str_start = i;
	while (file_str[i] != '\n' && file_str[i])
		i++;
	points.str_end = patch_spaces(file_str, i);
	return (points);
}

t_dictline	*parse_dict(char *file_str)
{
	t_dictline		*dict;
	t_parse_points	points;
	int				dict_index;
	int				i;

	i = 0;
	dict_index = 0;
	dict = ft_calloc(ft_count_lines(file_str) + 1, sizeof(t_dictline));
	while (file_str[i] != '\0')
	{
		points = gen_points(file_str, i);
		i = points.str_end;
		if (points.nbr_end == -1)
			return (0);
		dict[dict_index].nbr = ft_strndup(
				file_str + points.nbr_start, points.nbr_end - points.nbr_start);
		dict[dict_index].str = ft_strndup(
				file_str + points.str_start, points.str_end - points.str_start);
		dict_index++;
		while (file_str[i] == '\n' || file_str[i] == ' ')
			i++;
	}
	return (dict);
}

t_dictline	*parse_file(char *file_path)
{
	char		*str_dict;
	t_dictline	*dict;

	str_dict = read_file(file_path);
	if (str_dict == 0)
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	dict = parse_dict(str_dict);
	free(str_dict);
	return (dict);
}
