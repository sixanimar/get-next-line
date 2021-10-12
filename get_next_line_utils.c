/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguscins <jguscins@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:04:48 by jguscins          #+#    #+#             */
/*   Updated: 2021/10/11 16:25:34 by jguscins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int n)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != n && str[i])
		i++;
	if (str[i] == n)
		return ((char *)&str[i]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		f;
	char	*p;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (NULL);
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

int		ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}
