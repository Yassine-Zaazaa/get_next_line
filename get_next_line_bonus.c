/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 00:37:41 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/08 22:17:40 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;
	int			i;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0
		|| BUFFER_SIZE > INT_MAX || read(fd, buffer[fd], 0) < 0)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	if (!buffer[fd])
		buffer[fd] = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer[fd])
		return (NULL);
	line = ft_strjoin(NULL, buffer[fd]);
	if (!line)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	if (check_str(buffer[fd]))
		return (line);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer[fd], BUFFER_SIZE);
		if (i == -1 || (i == 0 && line[0] == '\0'))
			return (free(buffer[fd]), buffer[fd] = NULL, free(line), NULL);
		line = ft_strjoin(line, buffer[fd]);
		if (!line)
			return (free(buffer[fd]), buffer[fd] = NULL, NULL);
		if (check_str(buffer[fd]))
			return (line);
	}
	return (line);
}
