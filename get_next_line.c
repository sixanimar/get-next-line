/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguscins <jguscins@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:31:01 by jguscins          #+#    #+#             */
/*   Updated: 2021/10/10 19:29:22 by jguscins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_out(char *line, char *buff, int ret)
{
	char	*final;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_bzero(buff, ret);
	while (line[i] != '\n')
		i++;
	while (line[++i])
		buff[j++] = line[i];
	final = ft_cutline(line, '\n');
	return (final);
}

char	*ft_strchr(const char *str, int n)
{
	while (*str != n && *str)
		str++;
	if (*str == n)
		return ((char *)str);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
	{
		*p++ = 0;
	}
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*p;

	p = malloc(num * size);
	if (p)
		ft_bzero(p, num * size);
	return (p);
}

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE + 1];
	char			*line;
	int				ret;

	line = ft_calloc(1, 1);
	if (buff[0])
		line = ft_substr(buff, 0, ft_strlen(buff));
	while (!(ft_strchr(buff, '\n')))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1 || ret == 0)
			return (NULL);
		buff[ret] = '\0';
		line = ft_expand(line, buff);
		if (ret < BUFFER_SIZE && ret != 0)
			return (line);
	}
	return (ft_out(line, buff, ret));
}
