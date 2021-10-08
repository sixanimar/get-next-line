/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguscins <jguscins@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:04:48 by jguscins          #+#    #+#             */
/*   Updated: 2021/10/08 14:48:34 by jguscins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc (sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

char	*ft_expand(char *new, char *origin)
{
	char	*newline;

	newline = ft_strjoin(new, origin);
	free(new);
	new = newline;
	return(new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		f;
	char	*p;

	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (p)
	{
		i = 0;
		f = 0;
		while (s1[i])
		{
			p[i] = s1[i];
			i++;
		}
		while (s2[f])
		{
			p[i] = s2[f];
			i++;
			f++;
		}
		p[i] = 0;
		return (p);
	}
	return (0);
}

int		ft_strlen(const char *str)
{
	int	size;

	size = 0;
	while(str[size])
		size++;
	return(size);
}

char	*ft_cutline(char *line, char c)
{
	int		i;
	char	*newline;

	i = 0;
	while(line[i] != c)
		i++;
	newline = ft_substr(line, 0, i);
	free(line);
	line = newline;
	return(line);
}
