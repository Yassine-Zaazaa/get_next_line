#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int	i;
	char	*line;
	static char	str[BUFFER_SIZE + 1];

	i = 1;
	if(fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_strjoin(0, str);
	if(check_str(str))
		return (line);
	while(i > 0)
	{
		i = read(fd, str, BUFFER_SIZE);
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
		line = ft_strjoin(line, str);
		if(check_str(str))
			break;
	}
	return (line);
}
