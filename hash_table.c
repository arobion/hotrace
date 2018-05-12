/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 20:43:47 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/12 16:23:10 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int		main(void)
{
	t_table	table;
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
	if (key[0] == '\0')
		search(&table, value);
	while (hr_gnl(0, &key))
	{
		search(&table, key);
	}
	write(1, table.buff, table.index_buff);
	return (0);
}
