/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguscins <jguscins@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:12:24 by jguscins          #+#    #+#             */
/*   Updated: 2021/10/13 17:11:25 by jguscins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

// get_next_line.c
char	*get_next_line(int fd);
char	*new_buffer(char *buffer);
char	*returning_line(char *buffer);
char	*ft_read_into_buff(char *buff, int fd);

// get_next_line_utils.c
int		ft_strlen(const char *str);
char	*ft_strjoin(char *buff, char *temp);
char	*ft_strchr(char const *str, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

#endif
