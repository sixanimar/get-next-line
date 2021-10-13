/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguscins <jguscins@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:31:01 by jguscins          #+#    #+#             */
/*   Updated: 2021/10/13 17:06:19 by jguscins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	while (buffer[i] && buffer[i - 1] != '\n')
		i++;
	line = ft_substr(buffer, 0, i);
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
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buffer = ft_read_into_buff(buffer, fd);
	if (!buffer)
		return (NULL);
	line = returning_line(buffer);
	buffer = new_buffer(buffer);
	return (line);
}
