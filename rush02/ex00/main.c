/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	does_language_is_french(t_dictline *file_cnt)
{
	int	i;

	i = 0;
	while (file_cnt[i].str)
	{
		if (!ft_strcmp(file_cnt[i].str, "cent")
			&& !ft_strcmp(file_cnt[i].nbr, "100"))
			return (1);
		i++;
	}
	return (0);
}

void	call_nbeditor(char *str, t_dictline *file_cnt)
{
	char	*ptr;

	ptr = ft_calloc(1, 1);
	nbeditor(str, file_cnt, does_language_is_french(file_cnt), &ptr);
	if (ptr)
	{
		ptr[ft_strlen(ptr) - 1] = '\n';
		ft_putstr(ptr);
	}
	free(ptr);
}

int	main(int argc, char **argv)
{
	t_dictline	*file_cnt;
	char		*path;

	path = DICT_PATH;
	if (argc == 2 || argc == 3)
	{
		if (!(check_number(argv, argc - 1)))
			return (1 + ft_putstr("Error\n"));
		if (argc == 3)
			path = argv[1];
	}
	else if (argc > 3)
		return (1 + ft_putstr("Error\n"));
	file_cnt = parse_file(path);
	if (file_cnt == 0)
		return (1);
	if (argc == 1)
		pingpong(file_cnt);
	else
		call_nbeditor(argv[argc - 1], file_cnt);
	free_dict_array(file_cnt);
	return (0);
}
