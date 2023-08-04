/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbeditor2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	add_to_result(char **res, char *text)
{
	int	new_len;

	new_len = ft_strlen(*res) + ft_strlen(text) + 2;
	*res = ft_realloc(*res, ft_strlen(*res) + 1, new_len);
	ft_strcat(*res, text);
	ft_strcat(*res, " ");
	return (1);
}

int	add_if_in_dict(t_dictline *dict, int is_french,
		char **result, char *nb_copy)
{
	int	i;

	i = 0;
	while (dict[i].nbr != 0)
	{
		if (ft_strcmp(nb_copy, dict[i].nbr) == 0)
		{
			if (ft_strlen(nb_copy) > 3 && nb_copy[0] == '1' && (!is_french
					|| ft_strlen(nb_copy) > 6) && ft_strlen(nb_copy) % 3 == 1)
				nbeditor("1", dict, is_french, result);
			add_to_result(result, dict[i].str);
			return (1);
		}
		i++;
	}
	return (0);
}

int	add_multiples_of_thousand(char *nb_copy, int is_french,
		t_dictline *dict, char **result)
{
	char	*copy_copy;
	int		cut_at;
	int		i;

	copy_copy = ft_strndup(nb_copy, ft_strlen(nb_copy));
	if (ft_strlen(nb_copy) > 3)
	{
		cut_at = ft_strlen(nb_copy) % 3;
		if (cut_at == 0) 
			cut_at = 3;
		nb_copy[cut_at] = '\0';
		if ((!is_french || ft_strlen(copy_copy) > 6) || ft_strcmp(nb_copy, "1"))
			nbeditor(nb_copy, dict, is_french, result);
		nb_copy[0] = '1';
		ft_strcpy(nb_copy + 1, copy_copy + cut_at);
	}
	free(copy_copy);
	i = 0;
	while (dict[i].nbr != 0)
	{
		if (ft_strcmp(nb_copy, dict[i].nbr) == 0)
			return (add_to_result(result, dict[i].str));
		i++;
	}
	return (0);
}

int	add_multiples_of_ten(char *nb_copy, t_dictline *dict,
		int is_french, char **result)
{
	char	*copy_copy;
	int		i;
	int		j;

	copy_copy = ft_strndup(nb_copy, ft_strlen(nb_copy));
	j = ft_strlen(nb_copy) - 1;
	while (j > 0)
	{
		nb_copy[j] = '0';
		i = 0;
		while (dict[i].nbr != 0)
		{
			if (ft_strcmp(nb_copy, dict[i].nbr) == 0)
			{
				add_to_result(result, dict[i].str);
				nbeditor(copy_copy + j, dict, is_french, result);
				free(copy_copy);
				return (1);
			}
			i++;
		}
		j--;
	}
	free(copy_copy);
	return (0);
}
