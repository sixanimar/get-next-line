/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguscins <jguscins@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:04:48 by jguscins          #+#    #+#             */
/*   Updated: 2021/10/13 17:09:22 by jguscins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *buff, char *temp)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	if (!buff)
	{
		buff = malloc(1);
		buff[0] = '\0';
	}
	if (!temp || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(buff) + ft_strlen(temp) + 1)));
	if (!str)
		return (NULL);
	while (buff[++i])
		str[i] = buff[i];
	while (temp[j])
		str[i++] = temp[j++];
	str[i] = '\0';
	free(buff);
	return (str);
}

char	*ft_strchr(char const *str, char c)
{
	int		p;

	p = 0;
	if (!str)
		return (NULL);
	while (str[p])
		if (str[p++] == c)
			return ((char *)&str[--p]);
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
