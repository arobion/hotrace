/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 16:25:47 by arobion           #+#    #+#             */
/*   Updated: 2018/05/13 16:26:29 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int		ft_strcmp(char *line, int i1, int i2)
{
	while (!is_end(line, i1) && !is_end(line, i2))
	{
		if (line[i1] != line[i2])
			return (0);
		i1++;
		i2++;
	}
	if (!is_end(line, i1) || !is_end(line, i2))
		return (0);
	return (1);
}

void	search(t_table *table, char *line, int key)
{
	int		index;
	t_entry	*entry;

	index = hash(line, key, table->size);
	entry = (table->entry)[index];
	while (entry)
	{
		if (ft_strcmp(line, entry->key, key))
		{
			fill_buff(table, line, entry->val);
			return ;
		}
		entry = entry->next;
	}
	fill_buff_not_found(table, line, key);
}
