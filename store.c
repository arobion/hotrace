/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 16:13:15 by arobion           #+#    #+#             */
/*   Updated: 2018/05/12 16:17:19 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int		allocate_table(t_table *table, int size)
{
	int		i;

	i = 0;
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

void	store(t_table *table, char *key, char *val)
{
	int	index;

	index = hash(key, table->size);
	create_entry(&(table->entry)[index], key, val);
}
