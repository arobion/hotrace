/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 21:00:54 by gabtoubl          #+#    #+#             */
/*   Updated: 2018/05/12 15:58:16 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int			hr_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int			hr_putstr(const char *str)
{
	int		i;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
		++i;
	write(1, str, i);
	return (0);
}

int			hr_putendl(const char *str)
{
	if (hr_putstr(str))
		return (1);
	write(1, "\n", 1);
	return (0);
}
