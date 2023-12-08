/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 01:52:02 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/08 21:32:31 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len] && s[len] != '\n')
		len++;
	if (s && s[len] == '\n')
		len++;
	return (len);
}

int	check_str(char *str)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (str && str[i])
	{
		if (flag > 0)
			str[j++] = str[i];
		else if (str[i] == '\n')
			flag = 1;
		str[i] = '\0';
		i++;
	}
	return (flag);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (free(s1), NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] && s2[j] != '\n')
	{
		str[i + j] = s2[j];
		j++;
	}
	if (s2 && s2[j] == '\n')
		str[i + j++] = '\n';
	str[i + j] = '\0';
	if (s1)
		free(s1);
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*ret;
	size_t			i;
	size_t			final_size;
	unsigned char	*bytes;

	final_size = count * size;
	ret = malloc(final_size);
	if (!ret)
		return (NULL);
	bytes = (unsigned char *)ret;
	i = 0;
	while (i < final_size)
		bytes[i++] = 0;
	return (ret);
}
