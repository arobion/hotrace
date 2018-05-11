/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 19:50:24 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/15 22:18:23 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			<unistd.h>
#include			<stdlib.h>
#include			"hotrace.h"

static char			*hr_strjoin(char const *s1, char const *s2)
{
	int				s1_len;
	int				s2_len;
	char			*str;

	if ((str = (char *)malloc(hr_strlen(s1) + hr_strlen(s2) + 1)) == NULL)
		return (NULL);
	s1_len = -1;
	while (s1[++s1_len])
		str[s1_len] = s1[s1_len];
	s2_len = -1;
	while (s2[++s2_len])
		str[s1_len + s2_len] = s2[s2_len];
	str[s1_len + s2_len] = 0;
	free((void *)s1);
	free((void *)s2);
	return (str);
}

static int			hr_complete_line(int const fd, char **line)
{
	int				ret;
	char			*new_line;

	new_line = NULL;
	ret = hr_gnl(fd, &new_line);
	if (new_line != NULL)
		*line = hr_strjoin(*line, new_line);
	return (ret);
}

int					hr_gnl(int const fd, char **line)
{
	static char		buf[BUFF_SIZE + 1] = {0};
	static int		i = 0;
	int				j;

	if (!buf[i])
	{
		if ((i = read(fd, buf, BUFF_SIZE)) <= 0)
			return (i);
		buf[i] = 0;
		i = 0;
	}
	if ((*line = (char *)malloc(BUFF_SIZE - i + 2)) == NULL)
		return (-1);
	j = 0;
	while (buf[i] && buf[i] != '\n')
		(*line)[j++] = buf[i++];
	(*line)[j] = 0;
	if (buf[i] == '\n')
		++i;
	else
		return (hr_complete_line(fd, line));
	return (1);
}
