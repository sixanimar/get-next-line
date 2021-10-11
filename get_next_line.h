/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguscins <jguscins@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:12:24 by jguscins          #+#    #+#             */
/*   Updated: 2021/10/11 13:50:06 by jguscins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_expand(char *new, char *origin);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_cutline(char *line, char c);
int		ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t num, size_t size);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

#endif