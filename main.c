/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:23:20 by arobion           #+#    #+#             */
/*   Updated: 2018/05/11 18:28:07 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

/*
char	*parse_keyvalue(int *i, int *j, char *l)
{
	int		k;
	char	*key;

	k = 0;
	while (l[*i] != '\n' && *i < 4096)
		(*i)++;
	if (!(key = malloc(sizeof(char) * (*i - *j))))
		return ;
	while (*j < *i)
	{
		key[k] = l[*j];
		(*j)++;
		k++;
	}
	(*i)++;
	return (key);
}

void	save_tmp(char *tmp, char *l, int *i, int nb)
{
	int		k;

	k = 0;
	*i = 4096 - nb;
	if (!(tmp = malloc(sizeof(char) * (*i))))
		return ;
	while (k < *i)
	{
		tmp[k] = l[nb];
		nb++;
		k++;
	}
}

void	save_this_line(t_table *table, char *l, char *tmp, int *i)
{
	int		i_l;
	char	*key;
	char	*value;
	int		j_l;


	i_l = 0;
	if(*i == 0)
	{
		while (i_l < 4096)
		{
			j_l = i_l
			if (!(key = parse_keyvalue(&i_l, &i_j, l)))
				break ;
			j_l = i_l;
			if (!(value = parse_keyvalue(&i_l, &i_j, l)))
				break ;
			store(table, key, value);
			free(key);
			free(value);
		}
		if (i_l != 4096)
			save_tmp(tmp, l, i, i_l);
	}
	else
	{
		while(i_l < 4096)
		{
			j_l = i_l
			if (!(key
}

void	read_and_stock(t_table *table)
{
	char	l[4096];
	int		nb;
	int		i
		char	*tmp;

	i = 0;
	while (nb = read(0, l, 4096))
	{
		save_this_line(table, l, tmp, &i);
	}
}
*/

void	save_in_ret(char *l, char *ret, int *nb)
{
	int		i;

	i = 0;
	while (i < *nb)
	{
		ret[i] = l[i];
		i++;
	}
}

void	cpy_in_tmp(char *ret, char *tmp, int *nb)
{
	int		i;

	i = 0;
	while (i < *nb)
	{
		tmp[i] = ret[i];
		i++;
	}
}
void	cpy_tmp_in_ret(char *tmp, char *ret, int *nb)
{
	int		i;

	i = 0;
	while (i < *nb)
	{
		ret[i] = tmp[i];
		i++;
	}
}

void	cpy_l_in_ret(char *l, char *ret, int *i, int nb)
{
	int		j;

	j = 0;
	while (j < nb)
	{
		ret[*i] = l[j];
		(*i)++;
		j++;
	}
}

#include <stdio.h>
char	*save_std(void)
{
	char	*ret;
	char	*tmp;
	char	*l;
	int		i;
	int		nb;

	if (!(l = malloc(sizeof(char) * 10000000000)))
		return (NULL);
	if (!(ret = malloc(sizeof(char) * 1000000000)))
		return (NULL);
	i = read(0, l, 1000000000);
	save_in_ret(l, ret, &i);
	while ((nb = read(0, l, 1000000000)))
	{
		dprintf(1, "%d\n", i);
		if (!(tmp = malloc(sizeof(char) * i)))
			return (NULL);
		cpy_in_tmp(ret, tmp, &i);
		free(ret);
		if (!(ret = malloc(sizeof(char) * (i + nb))))
			return (NULL);
		cpy_tmp_in_ret(tmp, ret, &i);
		cpy_l_in_ret(l, ret, &i, nb);
		free(tmp);
	}
	return (ret);
}

int		main(void)
{
//	t_table *table;
	char	*std;
	
//	if (!(std = save_std()))
//		return (0);
	while (hr_gnl(0, &std));

	return (0);
}
