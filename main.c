/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 16:33:16 by arobion           #+#    #+#             */
/*   Updated: 2018/05/13 18:38:44 by nkamolba         ###   ########.fr       */
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

int		main(void)
{
	t_table	table;
	int		entry_nb;
	char	*line;
	int		i;

	entry_nb = fill_line(&line);
	if (!line)
		return (1);
	if (!allocate_table(&table, entry_nb))
		return (1);
	i = 0;
	store_phase(&table, line, &i);
	search_phase(&table, line, &i);
	write(1, table.buff, table.index_buff);
	free_all(&table, line);
	return (0);
}
