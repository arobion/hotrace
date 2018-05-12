/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 20:43:47 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/12 15:54:37 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "hotrace.h"

int		allocate_table(t_table *table, int size)
{
	int		i = 0;
	if (!(table->entry = (t_entry **)malloc(sizeof(t_entry*) * size)))
		return (0);
	while (i < size)
	{
		table->entry[i] = NULL;
		i++;
	}
	table->size = size;
	return (1);
}

int		create_entry(t_entry **entry, char *key, char *val)
{
	t_entry	*new;

	if (!(new = (t_entry *)malloc(sizeof(t_entry))))
		return (0);
	new->key = key;
	new->val = val;
	new->next = *entry;
	*entry = new;
	return (1);
}

int		hash(char *str, int	size)
{
	int		hash;

	hash = 5381;
	while (*str)
		hash = (((hash << 5) + hash) + *str++) % size;
	return (hash);
}

void	store(t_table *table, char *key, char *val)
{
	int	index;

	index = hash(key, table->size);
	create_entry(&(table->entry)[index], key, val);
}

void	print(t_table *table)
{
	t_entry	*entry;
	int		i;

	printf("--- Print Table ---\n");
	i = 0;
	while (i < table->size)
	{
		entry = (table->entry)[i];
		if (entry)
		{
			printf("entry %d\n", i);
			while (entry)
			{
				printf("key: %s, val: %s\n", entry->key, entry->val);
				entry = entry->next;
			}
			printf("\n");
		}
		i++;
	}
}

int		ft_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (0);
		str1++;
		str2++;
	}
	if (*str1 || *str2)
		return (0);
	return (1);
}

void	fill_buff(char *str, t_table *table)
{
	while (*str)
	{
		table->buff[table->index_buff] = *str++;
		(table->index_buff)++;
		if (table->index_buff == WRITE_SIZE)
		{
			write(1, table->buff, WRITE_SIZE);
			table->index_buff = 0;
		}
	}
	table->buff[table->index_buff] = '\n';
	(table->index_buff)++;
	if (table->index_buff == WRITE_SIZE)
	{
		write(1, table->buff, WRITE_SIZE);
		table->index_buff = 0;
	}
}

void	fill_buff_not_found(char *str, t_table *table)
{
	int		i;

	i = 0;
	while(*str)
	{
		
		table->buff[table->index_buff] = *str++;
		(table->index_buff)++;
		if (table->index_buff == WRITE_SIZE)
		{
			write(1, table->buff, WRITE_SIZE);
			table->index_buff = 0;
		}
	}
	while (i < 13)
	{
		
		table->buff[table->index_buff] = g_err_message[i++];
		(table->index_buff)++;
		if (table->index_buff == WRITE_SIZE)
		{
			write(1, table->buff, WRITE_SIZE);
			table->index_buff = 0;
		}
	}
}

void	search(t_table *table, char *key)
{
	int		index;
	t_entry	*entry;

	index = hash(key, table->size);
	entry = (table->entry)[index];
	while (entry)
	{

		if (ft_strcmp(entry->key, key))
		{
			fill_buff(entry->val, table);
			return ;
		}
		entry = entry->next;
	}
	fill_buff_not_found(key, table);
}


int		main(void)
{
	t_table	table;
	//t_entry	*entry;
	char	*key;
	char	*value;

	table.index_buff = 0;
	if (!(allocate_table(&table, 65536)))
		return (1);
	while (hr_gnl(0, &key) && hr_gnl(0, &value))
	{
		if (key[0] == '\0' || value[0] == '\0')
			break ;
		store(&table, key, value);
	}
	//	print(&table);
	if (key[0] == '\0')
		search(&table, value);
	while (hr_gnl(0, &key))
	{
		search(&table, key);
	}
	write(1, table.buff, table.index_buff);
	//	printf("--- Search Result ---\n");
	//	printf("%s: %s\n", str1, search(&table, str1));
	//	printf("%s: %s\n", str3, search(&table, str3));
	//	printf("%s: %s\n", str5, search(&table, str5));
	//	printf("%s: %s\n", str2, search(&table, str2));
	return (0);
}

