/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:43:30 by pnuti             #+#    #+#             */
/*   Updated: 2021/06/19 10:28:06 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	is_in(char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

static char	*copy_to_line(char *stat_line, char **line)
{
	char	*tmp;
	int		len;

	len = 0;
	while (stat_line[len] != '\n' && stat_line[len])
		len++;
	if (stat_line[len] == '\n')
	{
		*line = ft_substr(stat_line, 0, len);
		tmp = ft_strdup(&stat_line[len + 1]);
		free(stat_line);
		stat_line = ft_strdup(tmp);
		free(tmp);
	}
	else
	{
		*line = stat_line;
		stat_line = 0;
	}
	return (stat_line);
}

static int	return_val(char **stat_line, char **line, int res)
{
	if (res < 0)
		return (-1);
	else if (*stat_line == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	else
	{
		*stat_line = copy_to_line(*stat_line, line);
		if (*stat_line == 0)
			return (0);
		return (1);
	}		
}

int	get_next_line(int fd, char **line)
{
	static char	*stat_line[1025];
	char		*buf;
	char		*tmp;
	int			res;

	if (fd < 0 || fd > 1025 || BUFFER_SIZE < 1 || line == 0)
		return (-1);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (-1);
	res = read(fd, buf, BUFFER_SIZE);
	while (res > 0)
	{
		buf[res] = 0;
		if (stat_line[fd] == 0)
			stat_line[fd] = ft_strdup("");
		tmp = ft_strjoin(stat_line[fd], buf);
		free(stat_line[fd]);
		stat_line[fd] = tmp;
		if (is_in(buf, '\n'))
			break ;
		res = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (return_val(&stat_line[fd], line, res));
}
