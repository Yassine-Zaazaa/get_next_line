#ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H
#	include <stdio.h>
#	include <stdlib.h>
#	include <unistd.h>
#	include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_line(int fd, char	*str);
char	*get_next_line(int fd);
char	*ft_strncpy(char *dest, const char *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*next_line(char *str);

#endif