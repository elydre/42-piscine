/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pingpong.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*remove_extra_numeric(char *str)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = ft_calloc(ft_strlen(str) + 1, 1);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			new[j] = str[i];
			j++;
		}
		i++;
	}
	free(str);
	return (new);
}

char	*input(void)
{
	char	*new;

	new = ft_calloc(100, 1);
	read(0, new, 100);
	return (new);
}

void	unix_clear(void)
{
	ft_putstr("\033[A\033[2K");
}

void	pingpong(t_dictline *file_cnt)
{
	char	*str;

	while (1)
	{
		str = remove_extra_numeric(input());
		if (!str[0])
			continue ;
		unix_clear();
		ft_putstr(str);
		ft_putstr(": ");
		call_nbeditor(str, file_cnt);
		free(str);
	}
}
