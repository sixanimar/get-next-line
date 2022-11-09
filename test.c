/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguscins <jguscins@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:03:30 by jguscins          #+#    #+#             */
/*   Updated: 2021/10/13 16:22:56 by jguscins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("sampletext.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((line = get_next_line(fd)))
		printf("%s", line);
	if ((close(fd) == -1))
		return (-1);
}
