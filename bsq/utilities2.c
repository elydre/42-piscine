/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	warn_bad_flag(char *avi)
{
	ft_putstr("Unknown option: ");
	ft_putstr(avi);
	ft_putstr("\n");
}

int	get_file_len(char *file_path)
{
	char	buf[1000];
	int		fd;
	int		ret;
	int		len;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (0);
	len = 0;
	ret = read(fd, buf, 999);
	while (ret > 0)
	{
		len += ret;
		ret = read(fd, buf, 999);
	}
	close(fd);
	return (len);
}
