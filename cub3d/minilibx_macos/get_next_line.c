/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 10:26:15 by ashite            #+#    #+#             */
/*   Updated: 2019/11/03 17:36:59 by ashite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		freeta(char **s)
{
	if (*s != NULL)
	{
		free(*s);
		*s = NULL;
	}
	return (-1);
}

int		get_next_mini(int fd, char **saver)
{
	int		end;
	int		size;
	char	*temp;
	char	*str;

	size = 1;
	if ((str = (char*)malloc(BUFFER_SIZE + 1)) == NULL)
		return (-1);
	if (!(*saver))
	{
		if (!(*saver = malloc(1)))
			return (freeta(&str));
		**saver = '\0';
	}
	while ((end = ft_strchr(*saver, '\n')) == -1 && size > 0)
	{
		if ((size = read(fd, str, BUFFER_SIZE)) == -1)
			return (freeta(&str));
		str[size] = '\0';
		temp = *saver;
		*saver = ft_strjoin(*saver, str);
		freeta(&temp);
	}
	freeta(&str);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*saver[300];
	char		*temp;
	int			end;

	if (get_next_mini(fd, &saver[fd]) == -1)
		return (-1);
	end = ft_strchr(saver[fd], '\n');
	if (end == -1 && saver[fd] == NULL)
	{
		*line = ft_strdup("\0");
		return (0);
	}
	else if (end == -1)
	{
		*line = saver[fd];
		saver[fd] = NULL;
		return (0);
	}
	temp = saver[fd];
	*line = ft_substr(saver[fd], 0, end);
	saver[fd] = ft_substr(saver[fd], end + 1, ft_strlen(saver[fd]) - (end + 1));
	freeta(&temp);
	return (1);
}
