/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguscins <jguscins@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:12:24 by jguscins          #+#    #+#             */
/*   Updated: 2021/10/11 16:25:51 by jguscins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int n);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*read_line(int fd, char *buff);
char	*ft_cutline(char *buff);
char	*new_buff(char *buff);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#endif