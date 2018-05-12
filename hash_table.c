/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 20:43:47 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/12 17:43:25 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdio.h>

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
}
