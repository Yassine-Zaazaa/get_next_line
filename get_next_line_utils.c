#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	i = 0;
	while(s && s[i] != '\0' && s[i] != '\n')
		i++;
	if(s && s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;	

	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if(!ret)
		return (NULL);	
	i = 0;
	while(s1 && s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while(s2[j] != '\n' && s2[j])
		ret[i++] = s2[j++];
	if(s2[j] == '\n')
		ret[i++] = s2[j];
	ret[i] = '\0';
	if(s1)
		free(s1);
	return (ret);
}

int	check_str(char *str)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while(str[i] && str)
	{
		if(flag > 0)
			str[j++] = str[i];
		if(str[i] == '\n')
			flag = 1;
		str[i] = '\0';	
		i++;
	}
	return (flag);
}
