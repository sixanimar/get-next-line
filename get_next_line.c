/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguscins <jguscins@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:31:01 by jguscins          #+#    #+#             */
/*   Updated: 2021/10/12 01:14:36 by jguscins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buff;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = read_line(fd, buff);
	if (buff[0] == '\0')
		return (NULL);
	line = ft_cutline(buff);
	buff = new_buff(buff);
	return (line);
}

char	*read_line(int fd, char *buff)
{
	char	*temp;
	int		ret;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
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

char	*ft_cutline(char *buff)
{
	int		i;
	char	*line;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		line[i] = buff[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*new_buff(char *buff)
{
	char	*new_buff;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff)
	{
		free(buff);
		return (NULL);
	}
	new_buff = malloc(sizeof(char) * (ft_strlen(buff) - i + 1));
	if (!new_buff)
		return (NULL);
	i++;
	while (buff[i])
		new_buff[j++] = buff[i++];
	new_buff[j] = 0;
	free(buff);
	return (new_buff);
}
