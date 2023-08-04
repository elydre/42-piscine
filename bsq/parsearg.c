/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsearg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_arg	*init_arg(int ac)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	arg->x = 40;
	arg->y = 18;
	arg->prop = 5;
	arg->pos = 0;
	arg->seed = 43;
	arg->files = ft_calloc(ac, sizeof(char *));
	arg->used_entry = 0;
	return (arg);
}

t_arg	*check_arg(t_arg *arg)
{
	if (arg->x < 1)
	{
		ft_putstr("x must be greater than 0\n");
		return (free_and_ret(arg));
	}
	if (arg->y < 1)
	{
		ft_putstr("y must be greater than 0\n");
		return (free_and_ret(arg));
	}
	if (arg->prop < 0 || arg->prop > 100)
	{
		ft_putstr("density must be between 1 and 100\n");
		return (free_and_ret(arg));
	}
	if (arg->seed < 0)
	{
		ft_putstr("seed must be a positive number\n");
		return (free_and_ret(arg));
	}
	return (arg);
}

t_arg	*check_for_help(char *avi, t_arg *arg)
{
	if (ft_strcmp(avi, "-h") == 0)
	{
		free(arg->files);
		free(arg);
		return (NULL);
	}
	else if (!ft_strcmp(avi, "-r") || !ft_strcmp(avi, "-x")
		|| !ft_strcmp(avi, "-y") || !ft_strcmp(avi, "-s")
		|| !ft_strcmp(avi, "-d"))
		arg->used_entry = 1;
	return (arg);
}

t_arg	*check_other(int *i, char **av, t_arg *arg, int *file_i)
{
	if (ft_strcmp(av[*i], "-x") == 0)
		arg->x = ft_atoi(av[++(*i)]);
	else if (ft_strcmp(av[*i], "-r") == 0)
		;
	else if (ft_strcmp(av[*i], "-y") == 0)
		arg->y = ft_atoi(av[++(*i)]);
	else if (ft_strcmp(av[*i], "-s") == 0)
		arg->seed = ft_atoi(av[++(*i)]);
	else if (ft_strcmp(av[*i], "-d") == 0)
		arg->prop = ft_atoi(av[++(*i)]);
	else if (ft_strcmp(av[*i], "-p") == 0)
		arg->pos = 1;
	else if (av[*i][0] == '-')
	{
		warn_bad_flag(av[*i]);
		free(arg->files);
		free(arg);
		return (NULL);
	}
	else
	{
		arg->used_entry = 2;
		arg->files[(*file_i)++] = av[*i];
	}
	return (arg);
}

t_arg	*parsearg(int ac, char **av)
{
	t_arg	*arg;
	int		file_i;
	int		i;

	i = 1;
	file_i = 0;
	arg = init_arg(ac);
	while (i < ac)
	{
		arg = check_for_help(av[i], arg);
		if (!arg)
			return ((t_arg *) HELP_CODE);
		arg = check_other(&i, av, arg, &file_i);
		if (!arg)
			return (NULL);
		i++;
	}
	return (check_arg(arg));
}
