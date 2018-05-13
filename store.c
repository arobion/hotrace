/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 16:21:53 by arobion           #+#    #+#             */
/*   Updated: 2018/05/13 18:24:52 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int		create_entry(t_entry **entry, char *line, int key, int val)
{
	t_entry	*new;

	(void)line;
	if (!(new = (t_entry *)malloc(sizeof(t_entry))))
		return (0);
	new->key = key;
	new->val = val;
	new->next = *entry;
	*entry = new;
	return (1);
}

void	store(t_table *table, char *line, int key, int val)
{
	int	index;

	index = hash(line, key, table->size);
	create_entry(&(table->entry)[index], line, key, val);
}
