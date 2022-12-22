#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	i = 0;
	while(s[i++]);
	return (i - 1);
}

char	*ft_strchr(const char *s, int c)
{
	while(*s != (unsigned char)c)
	{
		if(!*s++)
			return (0);
	}
	return ((char *)s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	char	*str1;
	char 	*str2;
	size_t	i;
	
	if(!s1 || !s2)
		return (NULL);
	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if(!ret)
		return (NULL);	
	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	while(*str1)
	{
		ret[i] = *str1;
		i++;
		str1++;
	}
	while(*str2)
	{
		ret[i] = *str2;
		i++;
		str2++;
	}
	ret[i] = '\0';
	return (ret);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*str;
	const char 	*ptr;
	size_t		i;

	if(!dest && !src)
		return (NULL);
	if(dest == src)
		return (NULL);
	str = (char *)dest;
	ptr = (const char *)src;
	i = 0;
	while(i < n)
	{
		str[i] = ptr[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;
	
	len = ft_strlen(src);
	if(!size)
		return (len);
	if(len >= size)
		len = size - 1;
	ft_memcpy(dest, src, len);
	dest[len] = 0;
	return (ft_strlen(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	s_len;

	if(!s)
		return (NULL);
	s_len = ft_strlen(s);
	if(s_len <= start)
	{	
		len = 0;
		start = s_len;
	}
	if(len > s_len - start)
		len = s_len - start;
	ret = malloc(sizeof(char) * (len + 1));
	if(!ret)
		return (NULL);
	ft_strlcpy(ret, &s[start], len + 1);
	return (ret);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int	i;

	i = 0;
	if(!s)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if(!str)
		return (NULL);
	while(s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
