/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 20:43:47 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/13 15:44:46 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdio.h>
/*
   int		main(void)
   {
   t_table	table;
   char	*key;
   char	*value;

   table.index_buff = 0;
   if (!(allocate_table(&table, HASH_TABLE_SIZE)))
   return (1);
   while (hr_gnl(0, &key))
   {
   if (key[0] == '\0')
   break ;
   if (!hr_gnl(0, &value))
   break ;
   if (value[0] == '\0')
   {
   free(value);
   break ;
   }
   store(&table, key, value);
   }
   if (key)
   free(key);
   while (hr_gnl(0, &key))
   search(&table, key);
   write(1, table.buff, table.index_buff);
   free_table(table.entry);
   return (0);
   }*/

int		check_end_store(char *line, int i)
{
	if (line[i - 1] == '\0')
		return (0);
	if (line[i] == '\n')
		return (0);
	return (1);
}

void	store_phase(t_table *table, char *line, int *i)
{
	int		key;
	int		value;

	key = *i;
	while (line[*i] != '\n' && line[*i] != '\0')
		(*i)++;
	(*i)++;
	value = *i;
	if (!check_end_store(line, *i))
		return ;
	store(table, key, value, line);
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
		store(table, key, value, line);
	}
}

int		check_end_search(char *line, int i)
{
	if (line[i - 1] == '\0')
		return (0);
	return (1);
}

void	search_phase(t_table *table, char *line, int *i)
{
	int		key;

	while (check_end_search(line, *i))
	{
		while (line[*i] != '\n' && line[*i] != '\0')
			*i++;
		(*i)++;
		key = (*i);
		if (!check_end_search(line, *i))
			return ;
		search(table, line, key);
	}
}


int		main(void)
{
	t_table	table;
	char	*line;
	int		i;

	(void)table;
	table.index_buff = 0;
	if (!(allocate_table(&table, HASH_TABLE_SIZE)))
		return (1);
	i = fill_line(&line);
	i = 0;
	store_phase(&table, line, &i);
	search_phase(&table, line, &i);
	return (0);
}


