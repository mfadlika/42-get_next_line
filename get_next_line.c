/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadlika <mfadlika@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:06:52 by mfadlika          #+#    #+#             */
/*   Updated: 2022/08/16 17:06:54 by mfadlika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_str(int fd, char *read_str)
{
	char	*line;
	int		read_bytes;

	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(read_str, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, line, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(line);
			return (NULL);
		}
		line[read_bytes] = '\0';
		read_str = ft_strjoin(read_str, line);
	}
	free(line);
	return (read_str);
}

char	*ft_get_line(char *read_str)
{
	int		index;
	char	*str;

	index = 0;
	if (!read_str[index])
		return (NULL);
	while (read_str[index] && read_str[index] != '\n')
		++index;
	str = (char *)malloc(sizeof(char) * (index + 2));
	if (!str)
		return (NULL);
	index = 0;
	while (read_str[index] && read_str[index] != '\n')
	{
		str[index] = read_str[index];
		++index;
	}
	if (read_str[index] == '\n')
	{
		str[index] = read_str[index];
		++index;
	}
	str[index] = '\0';
	return (str);
}

char	*ft_next_line(char *read_str)
{
	int		index;
	int		index2;
	char	*str;

	index = 0;
	while (read_str[index] && read_str[index] != '\n')
		++index;
	if (!read_str[index])
	{
		free(read_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(read_str) - index + 1));
	if (!str)
		return (NULL);
	++index;
	index2 = 0;
	while (read_str[index])
		str[index2++] = read_str[index++];
	str[index2] = '\0';
	free(read_str);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*read_line;
	static char	*read_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	read_str = ft_read_str(fd, read_str);
	if (!read_str)
		return (NULL);
	read_line = ft_get_line(read_str);
	read_str = ft_next_line(read_str);
	return (read_line);
}
