/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbeditor1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ret_free(void *ptr1)
{
	free(ptr1);
	return (0);
}

int	raise_error(char **result, void *ptr1)
{
	ft_putstr("Dict Error\n");
	free(*result);
	free(ptr1);
	*result = NULL;
	return (1);
}

int	set_digits(char *nb_copy)
{
	nb_copy[0] = '1';
	nb_copy[1] = '0';
	return (1);
}

int	end_nbeditor(char *nb_copy, t_dictline *dict,
		int is_french, char **result)
{
	char	*copy_copy;
	char	old;

	copy_copy = ft_strndup(nb_copy, ft_strlen(nb_copy));
	old = nb_copy[0];
	if (add_multiples_of_ten(nb_copy, dict, is_french, result))
		return (ret_free(copy_copy));
	nb_copy[0] = old;
	if (ft_strlen(nb_copy) < 4)
	{
		nb_copy[1] = '\0';
		if (nbeditor(nb_copy, dict, is_french, result))
			return (1);
		if (set_digits(nb_copy) && ft_strcmp(copy_copy, nb_copy))
		{
			if (nbeditor(nb_copy, dict, 1, result)
				|| nbeditor(copy_copy + 1, dict, is_french, result))
				return (1 + ret_free(copy_copy));
		}
		else
			return (raise_error(result, copy_copy));
	}
	else
		return (raise_error(result, copy_copy));
	return (ret_free(copy_copy));
}

int	nbeditor(char *nb, t_dictline *dict, int is_french, char **result)
{
	char	*nb_copy;

	nb_copy = ft_strndup(nb, ft_strlen(nb));
	while (nb_copy[0] == '0' && nb_copy[1])
		ft_strcpy(nb_copy, nb_copy + 1);
	if (ft_strlen(nb_copy) == 3 && nb_copy[0] == '1' && !is_french)
	{
		if (nbeditor("1", dict, is_french, result))
		{
			free(nb_copy);
			return (1);
		}
	}
	if (add_if_in_dict(dict, is_french, result, nb_copy)
		|| add_multiples_of_thousand(nb_copy, is_french, dict, result))
	{
		free(nb_copy);
		return (0);
	}
	return (end_nbeditor(nb_copy, dict, is_french, result) + ret_free(nb_copy));
}
