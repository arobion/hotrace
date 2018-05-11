/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 20:43:47 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/11 21:44:32 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "hash_table.h"

int		allocate_table(t_table *table, int size)
{
	if (!(table->entry = (t_entry **)malloc(sizeof(t_entry*) * size)))
		return (0);
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
	int		sum;

	sum = 0;
	while (*str)
		sum += *str++;
	return (sum % size);
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

char	*search(t_table *table, char *key)
{
	int		index;
	t_entry	*entry;

	index = hash(key, table->size);
	entry = (table->entry)[index];
	while (entry)
	{
		if (ft_strcmp(entry->key, key))
			return (entry->val);
		entry = entry->next;
	}
	return (NULL);
}

/*
int		main(void)
{
	t_table	table;
	t_entry	*entry;
	char	str1[] = "hello";
	char	str2[] = "world";
	char	str3[] = "foo";
	char	str4[] = "bar";
	char	str5[] = "olleh";
	char	str6[] = "dlrow";

	if (!(allocate_table(&table, 256)))
		return (1);
	store(&table, str1, str2);
	store(&table, str3, str4);
	store(&table, str5, str6);
	print(&table);

	printf("--- Search Result ---\n");
	printf("%s: %s\n", str1, search(&table, str1));
	printf("%s: %s\n", str3, search(&table, str3));
	printf("%s: %s\n", str5, search(&table, str5));
	printf("%s: %s\n", str2, search(&table, str2));
	return (0);
}
*/
