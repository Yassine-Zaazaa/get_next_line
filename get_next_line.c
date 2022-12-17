#include "get_next_line.h"

char	*get_line(int fd, char *str)
{
	char	*buff;
	int	r;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buff)
		return (NULL);
	r = 1;
	while(r && !ft_strchr(str, '\n'))
	{
		r = read(fd, buff, BUFFER_SIZE);
		if(r == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[r] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;
	int		i;

	if(!str)
		str = ft_strdup("");
	if(fd < 0 || fd > 4095 || BUFFER_SIZE < 1)
		return (NULL);
	str = get_line(fd, str);
	if(!str)
		return (NULL);
	i = 0;
	while(str[i] && str[i] != '\n')
		i++;
	if(!str[i])
		i--;
	line = malloc(sizeof(char) * ++i);
	if(!line)
		return (NULL);
	if(str[i] == '\0')
		i--;
	line = ft_strncpy(line, str, i);
	str = next_line(str);
	return (line); 	
}
/*
int	main(void)
{
	int	fd = open("s.txt", O_RDONLY);
	if(!fd)
		printf("file doesnt exist\n");
	else
	{
		printf("%s\n", get_next_line(fd));
		printf("%s\n", get_next_line(fd));
		printf("%s\n", get_next_line(fd));
		printf("%s\n", get_next_line(fd));	
	}
	close(fd);
	return (0);
}*/
