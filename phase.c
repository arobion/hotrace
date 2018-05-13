/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 16:27:37 by arobion           #+#    #+#             */
/*   Updated: 2018/05/13 16:54:06 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int		check_end_store(char *line, int i)
{
	if (line[i - 1] == '\0')
		return (0);
	if (line[i] == '\n')
		return (0);
	return (1);
}

void	store_phase2(char *line, int *i)
{
	while (line[*i] != '\n' && line[*i] != '\0')
		(*i)++;
	(*i)++;
}

void	store_phase(t_table *table, char *line, int *i)
{
	int		key;
	int		value;

	key = *i;
	store_phase2(line, i);
	value = *i;
	if (!check_end_store(line, *i))
		return ;
	store(table, line, key, value);
	while (check_end_store(line, *i))
	{
		while (line[*i] != '\n' && line[*i] != '\0')
			(*i)++;
		(*i)++;
		key = *i;
		if (!check_end_store(line, *i))
			return ;
		while (line[*i] != '\n' && line[*i] != '\0')
			(*i)++;
		(*i)++;
		value = *i;
		if (!check_end_store(line, *i))
			return ;
		store(table, line, key, value);
	}
}

int		check_end_search(char *line, int i)
{
	if (i > 1)
	{
		if (line[i - 2] == '\n' && line[i - 1] == '\n')
			return (1);
	}
	if (line[i - 1] == '\0')
		return (0);
	if (line[i] == '\0')
		return (0);
	return (1);
}

void	search_phase(t_table *table, char *line, int *i)
{
	int		key;
	int		j;

	j = 0;
	while (check_end_search(line, *i))
	{
		while (line[*i] != '\n' && line[*i] != '\0')
			(*i)++;
		(*i)++;
		key = (*i);
		if (!check_end_search(line, *i))
			return ;
		search(table, line, key);
	}
}
