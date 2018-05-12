/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:24:06 by arobion           #+#    #+#             */
/*   Updated: 2018/05/12 15:53:58 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 1080
# define WRITE_SIZE 4096

static char			g_err_message[13] =
{
	':',
	' ',
	'N',
	'o',
	't',
	' ',
	'f',
	'o',
	'u',
	'n',
	'd',
	'.',
	'\n'
};

typedef struct		s_entry
{
	char			*key;
	char			*val;
	struct s_entry	*next;
}					t_entry;

typedef struct		s_table
{
	char			buff[WRITE_SIZE];
	int				index_buff;
	int				size;
	struct s_entry	**entry;
}					t_table;

int					hr_gnl(int const fd, char **line);
int					hr_strlen(const char *str);

#endif
