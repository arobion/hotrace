/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:48:01 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/11 19:22:03 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLE_H
# define HASH_TABLE_H

typedef struct		s_entry
{
	char			*key;
	char			*val;
	struct s_entry	*next;
}

typedef struct		s_table
{
	int				size;
	struct s_entry	**table;
}					t_table;

t_table	*create_table(int size);
//malloc depend on size

void	create_entry(t_entry *entry, char *key, char *val);
//while entry->key != key
//next
//
//if found
//entry->val = val;
//return;
//
//if entry == null
//malloc new_entry
//new_entry = malloc
//new_entry->key = key
//new_entry->value = val
//new_entry->next = next
//return;

//****************************************************************************************
void	store(t_table *table, char *key, char *val);
/*
 * int index;
index = hash(key);
create_entry(table[index], key, value);
*/

int		hash(char *str);
// calculate index from str;

char	*find_entry(t_entry *entry, char *key);
// loop though linked list to find the key
// if found
// 	return val;
// else
// 	return null;

//************************************************************************************
char	*search(char *key);
//int index;
//index = hash(key);
//ret = find_entry(table[index], key);
//if ret == null
//return "not found";
//else
//return ret;



#endif
