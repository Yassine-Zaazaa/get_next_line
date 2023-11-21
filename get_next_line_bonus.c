/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 00:37:41 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/11/20 22:06:43 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[10240][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd][BUFFER_SIZE] = '\0';
	line = ft_strjoin(NULL, buffer[fd]);
	if (check_str(buffer[fd]))
		return (line);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer[fd], BUFFER_SIZE);
		if (i == -1)
			return (free(line), NULL);
		if (i == 0 && line[0] == '\0')
			return (free(line), NULL);
		buffer[fd][i] = '\0';
		line = ft_strjoin(line, buffer[fd]);
		if (check_str(buffer[fd]))
			return (line);
	}
	return (line);
}
