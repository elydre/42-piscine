/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	triming_spaces(char **str, int i, int index)
{
	int	j;
	int	k;

	j = i;
	k = 0;
	while (str[index][j])
	{
		str[index][k] = str[index][j];
		k++;
		j++;
	}
	str[index][k] = 0;
}

int	check_number(char **arg, int index)
{
	int	i;

	i = 0;
	while (arg[index][i] == 32)
		i++;
	if (i != 0)
		triming_spaces(arg, i, index);
	i = 0;
	if (!(arg[index][i] >= '0' && arg[index][i] <= '9'))
		return (0);
	while (arg[index][i])
	{
		if (arg[index][i] == '.' || arg[index][i] == ',')
			return (0);
		if (!(arg[index][i] >= '0' && arg[index][i] <= '9'))
		{
			arg[index][i] = 0;
			return (1);
		}
		i++;
	}
	return (1);
}
