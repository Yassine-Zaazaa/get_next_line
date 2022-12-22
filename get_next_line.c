#include "get_next_line.h"

char	*read_line(int fd, char *static_str)
{
	int	r;
	char	*tmp;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buffer)
		return (NULL);
	r = 0;
	if(!static_str)
		static_str = ft_strdup("");
	while(!ft_strchr(static_str, '\n'))
	{
		r = read(fd, buffer, BUFFER_SIZE);
		buffer[r] = '\0';
		if(r == 0)
			break;
		tmp = static_str;
		if(!(static_str = ft_strjoin(static_str, buffer)))
		{
			free(tmp);
			free(buffer);
			return (NULL);
		}
		free(tmp);
	}
	free(buffer);
	return (static_str);
}

char	*get_next_line(int fd)
{
	static char	*static_str;
	char		*tmp;
	int		p;
	char		*line;

	if(fd < 0 || read(fd, NULL, 0) != 0 || BUFFER_SIZE < 0)
		return (NULL);
	static_str = read_line(fd, static_str);
	p = 0;
	if(!ft_strchr(static_str, '\n'))
	{
		free(static_str);
		return (NULL);
	}
	p = ft_strchr(static_str, '\n') - static_str;
	tmp = static_str;
	line = ft_substr(static_str, 0, p + 1);
	if(!(static_str = ft_strdup(static_str + p + 1)))
		return (NULL);
	free(tmp);
	return (line);
}
/*
int	main()
{
	int	fd = open("4lines.txt", O_RDONLY);

	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	return (0);
}*/
