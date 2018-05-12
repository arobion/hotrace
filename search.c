/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 16:18:51 by arobion           #+#    #+#             */
/*   Updated: 2018/05/12 16:32:39 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int		hash(char *str, int size)
{
	int		hash;

	hash = 5381;
	while (*str)
		hash = (((hash << 5) + hash) + *str++) % size;
	return (hash);
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
			free(key);
			return ;
		}
		entry = entry->next;
	}
	fill_buff_not_found(key, table);
	free(key);
}
