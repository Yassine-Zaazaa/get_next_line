#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int	i;
	char	*line;
	static char	str[FOPEN_MAX][BUFFER_SIZE + 1];

	i = 1;
	if(fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_strjoin(0, str[fd]);
	if(check_str(str[fd]))
		return (line);
	while(i > 0)
	{
		i = read(fd, str[fd], BUFFER_SIZE);
		if(i == -1)
		{
			free(line);
			return (NULL);
		}
		if(i == 0 && line[0] == '\0')
		{
			free(line);
			return (NULL);
		}	
		line = ft_strjoin(line, str[fd]);
		if(check_str(str[fd]))
			break;
	}
	return (line);
}
