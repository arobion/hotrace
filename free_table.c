/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 16:23:57 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/12 16:47:19 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	free_table(t_entry **entry)
{
	int		i;
	t_entry *current;
	t_entry *temp;

	i = 0;
	while (i < HASH_TABLE_SIZE)
	{
		current = entry[i];
		while (current)
		{
			free(current->key);
			free(current->val);
			temp = current->next;
			free(current);
			current = temp;
		}
		i++;
	}
	free(entry);
}
