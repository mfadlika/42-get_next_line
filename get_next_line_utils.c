/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadlika <mfadlika@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:07:04 by mfadlika          #+#    #+#             */
/*   Updated: 2022/08/16 17:07:06 by mfadlika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	index;

	index = 0;
	if (!s)
		return (0);
	while (s[index] != '\0')
		++index;
	return (index);
}

char	*ft_strchr(char *s, int c)
{
	int	index;

	index = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[index] != '\0')
	{
		if (s[index] == (char) c)
			return ((char *)&s[index]);
		++index;
	}
	return (0);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	index;
	size_t	index2;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	index = -1;
	index2 = 0;
	if (left_str)
		while (left_str[++index] != '\0')
			str[index] = left_str[index];
	while (buff[index2] != '\0')
		str[index++] = buff[index2++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}
