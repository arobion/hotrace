/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:51:50 by arobion           #+#    #+#             */
/*   Updated: 2018/05/13 14:32:18 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_save	*new_cell(char *l, int i)
{
	t_save	*cell;
	int		j;

	j = 0;
	if (!(cell = malloc(sizeof(t_save))))
		return (0);
	if (!(cell->save_line = malloc(sizeof(char) * READ_SIZE + 1)))
		return (0);
	while (j < READ_SIZE)
	{
		cell->save_line[j] = l[j];
		j++;
	}
	cell->save_line[j] = '\0';
	cell->size = i;
	cell->next = NULL;
	return (cell);
}

void	check_entry(char **line, int *i, int *ret, int *stop)
{
	if ((*line)[*i] == '\n')
	{
		(*stop)++;
		if (*i > 0 && (*line)[*i - 1] == '\n')
			*ret = *stop;
	}
	(*i)++;
}

int		rewrite(t_save *save, int tot, char **line)
{
	t_save	*tmp;
	int		i;
	int		j;
	int		ret;
	int		stop;

	stop = 0;
	if (!(*line = malloc(sizeof(char) * (tot + 1))))
		return (0);
	i = 0;
	while (i < tot)
	{
		j = -1;
		while (++j < READ_SIZE && i < tot)
		{
			(*line)[i] = save->save_line[j];
			check_entry(line, &i, &ret, &stop);
		}
		tmp = save->next;
		free(save->save_line);
		free(save);
		save = tmp;
	}
	(*line)[i] = '\0';
	return (ret / 2);
}

int		save_gnl(t_save *save, char **line, int nb)
{
	t_save	*tmp;
	int		i;
	char	*l;
	int		tot;

	tot = nb;
	if (!(l = malloc(sizeof(char) * READ_SIZE + 1)))
		return (0);
	tmp = save;
	while ((i = read(0, l, READ_SIZE)))
	{
		tot += i;
		l[READ_SIZE] = 0;
		if (!(tmp->next = new_cell(l, i)))
			return (0);
		tmp = tmp->next;
	}
	return (rewrite(save, tot, line));
}

int		fill_line(char **line)
{
	t_save	*save;
	char	*l;
	int		i;

	if (!(l = malloc(sizeof(char) * READ_SIZE + 1)))
		return (0);
	i = read(0, l, READ_SIZE);
	l[READ_SIZE] = '\0';
	if (!(save = new_cell(l, i)))
		return (0);
	return (save_gnl(save, line, i));
}
