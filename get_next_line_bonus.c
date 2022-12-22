#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int	i;
	char	*line;
	static char	str[FOPEN_MAX][BUFFER_SIZE + 1];

	i = 1;
	if(fd < 0 || BUFFER_SIZE < 1)
		return (0);
	line = ft_strjoin(0, str);
	if(check_str(str))
		return (line);
	while(i > 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if(i == -1)
			return (ft_free(line));
		if(i == 0 && line[0] == '\0')
			return (ft_free(line));
		line = ft_strjoin(line, str);
		if(check_str(str))
			break;
	}
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
