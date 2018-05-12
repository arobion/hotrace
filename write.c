/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 16:22:10 by arobion           #+#    #+#             */
/*   Updated: 2018/05/12 16:24:55 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

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
