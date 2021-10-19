/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgusins <jguscins@student.42wolfsburg.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:25:38 by jgusins           #+#    #+#             */
/*   Updated: 2021/10/20 00:53:22 by jgusins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_into_buff(char *buff, int fd)
{
	char	*temp;
	int		ret;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	ret = 1;
	while (!ft_strchr(buff, '\n') && ret != 0)
	{
		ret = read(fd, temp, BUFFER_SIZE);
		if (ret == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[ret] = 0;
		buff = ft_strjoin(buff, temp);
	}
	free(temp);
	return (buff);
}

char	*returning_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[0])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_substr(buffer, 0, i + 1);
	return (line);
}

char	*new_buffer(char *buffer)
{
	char	*newbuff;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	newbuff = ft_substr(buffer, i + 1, ft_strlen(buffer) - i + 1);
	free(buffer);
	return (newbuff);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[1024];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buffer[fd] = ft_read_into_buff(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	line = returning_line(buffer[fd]);
	buffer[fd] = new_buffer(buffer[fd]);
	return (line);
}
