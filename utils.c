/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 16:26:55 by arobion           #+#    #+#             */
/*   Updated: 2018/05/13 16:27:33 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int		is_end(char *line, int i)
{
	if (!line[i] || line[i] == '\n')
		return (1);
	return (0);
}

int		hash(char *line, int i, int table_size)
{
	int		hash;

	hash = 5381;
	while (!is_end(line, i))
		hash = (((hash << 5) + hash) + line[i++]) % table_size;
	return (hash);
}

void	free_all(t_table *table, char *line)
{
	int		i;
	t_entry *current;
	t_entry *temp;

	i = 0;
	while (i < table->size)
	{
		current = (table->entry)[i];
		while (current)
		{
			temp = current->next;
			free(current);
			current = temp;
		}
		i++;
	}
	free(table->entry);
	free(line);
}
