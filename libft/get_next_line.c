/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 19:17:04 by arcohen           #+#    #+#             */
/*   Updated: 2018/06/19 14:00:04 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*mallcat(char **line, char *buf, size_t i)
{
	char *ret;

	if (*line == 0)
		return (ft_strsub(buf, 0, i));
	ret = ft_strnew(ft_strlen(*line) + ft_strlen(buf));
	ft_strcpy(ret, *line);
	ft_strncat(ret, buf, i);
	free(*line);
	return (ret);
}

static int	findwrite(char *buf, char **line)
{
	ssize_t i;

	if (!ft_strlen(buf))
		return (0);
	if ((i = ft_strchr(buf, '\n') - buf) >= 0)
	{
		*line = mallcat(line, buf, i);
		ft_strcpy(buf, (buf + i + 1));
		return (1);
	}
	else
	{
		*line = mallcat(line, buf, ft_strlen(buf));
		ft_strclr(buf);
		return (0);
	}
}

int			get_next_line(const int fd, char **line)
{
	char static	*buf;
	ssize_t		n;

	if (!buf)
		buf = ft_strnew(BUFF_SIZE);
	if (fd < 0 || line == 0 || read(fd, buf, 0) < 0)
		return (-1);
	*line = 0;
	if (findwrite(buf, line))
		return (1);
	while ((n = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[n] = 0;
		if (findwrite(buf, line))
			return (1);
	}
	if (*line)
		return (1);
	return (0);
}
