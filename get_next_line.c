/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguscins <jguscins@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:31:01 by jguscins          #+#    #+#             */
/*   Updated: 2021/10/08 16:09:33 by jguscins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_out(char *line)
{
	char	*final;

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

	line = calloc(1, 1);
	ret = BUFFER_SIZE;
	while (ret == BUFFER_SIZE || ret == -1)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		buff[ret] = '\0';
		line = ft_expand(line, buff);
		if ((ft_strchr(line, '\n')))
		{
			ft_bzero(ft_strchr(buff, '\n'), ret);
			return (ft_out(line));
		}
	}
	return (NULL);

}
