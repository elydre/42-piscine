/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readstdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	is_first_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n' && str[i + 1] == '\0')
		return (1);
	return (0);
}

int	calc_line_count(char *buf, int ret, int linecount)
{
	if (linecount == -2)
	{
		if (is_first_line(buf))
			linecount = ft_atoin(buf, ft_line_len(buf) - 3);
		else
			linecount = -1;
	}
	else if (linecount > 0 && buf[ret - 1] == '\n')
		linecount--;
	return (linecount);
}

int	put_newline(void)
{
	ft_putchar('\n');
	return (1);
}

char	*read_stdin(void)
{
	char					buf[1000];
	char					*str;
	unsigned long long		str_len;
	int						ret;
	int						linecount;

	str = ft_calloc(1, sizeof(char));
	str_len = 0;
	ret = 0;
	linecount = -2;
	while (1)
	{
		ret = read(0, buf, 999);
		buf[ret] = '\0';
		linecount = calc_line_count(buf, ret, linecount);
		str = ft_realloc(str, str_len, str_len + ret + 1);
		ft_strcat(str, buf);
		str_len += ret;
		if (linecount == 0 && put_newline())
			break ;
		if (ret == 0)
			break ;
	}
	return (str);
}
