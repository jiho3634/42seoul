/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim2 <jihokim2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:30:58 by jihokim2          #+#    #+#             */
/*   Updated: 2022/12/20 13:31:01 by jihokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	excetion(int fd)
{
	if (fd < 0 || fd > 255)
		return (-1);
	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > 4096)
		return (-1);
	return (0);
}

char	*buf_check(char *buf)
{
	char	*temp;

	temp = ft_strchr(buf, '\n');
	if (temp)
		temp = ft_strdup(temp + 1);
	return (temp);
}

char	*ft_read(int fd, char *buf)
{
	int		ret;
	char	*temp;

	ret = read(fd, buf, BUFFER_SIZE);
	if (ret < 0)
		return (NULL);
	else if (ret == 0)
	{
		temp = (char *) malloc (sizeof(char) * 1);
		*temp = '\0';
	}
	else if (ret >= BUFFER_SIZE)
	{
		buf[BUFFER_SIZE] = '\0';
		temp = buf;
	}
	else
	{
		buf[ret] = '\0';
		temp = buf;
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*temp;

	if (excetion(fd))
		return (NULL);
	line = buf_check(buf);
	if (line == 0)
	temp = ft_read(fd, buf);
	ft_strjoin(line, temp);
	return (line);
}
