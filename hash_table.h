/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:48:01 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/11 21:34:33 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLE_H
# define HASH_TABLE_H

typedef struct		s_entry
{
	char			*key;
	char			*val;
	struct s_entry	*next;
}					t_entry;

typedef struct		s_table
{
	int				size;
	struct s_entry	**entry;
}					t_table;

#endif
