#include "hotrace.h"
#include <stdio.h>

int		allocate_table(t_table *table, int size)
{
	int		i;

	i = 0;
	if (!(table->entry = (t_entry **)malloc(sizeof(t_entry*) * size)))
		return (0);
	while (i < size)
	{
		table->entry[i] = NULL;
		i++;
	}
	table->size = size;
	return (1);
}

int		is_end(char *line, int i)
{
	if (!line[i] || line[i] == '\n')
		return (1);
	return (0);
}

int		hash(char *line, int i, int table_size)
{
	int		hash;

	hash = 5381;
	while (!is_end(line, i))
		hash = (((hash << 5) + hash) + line[i++]) % table_size;
	return (hash);
}

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

int		ft_strcmp(char *line, int i1, int i2)
{
	while (!is_end(line, i1) && !is_end(line, i2))
	{
		if (line[i1] != line[i2])
			return (0);
		i1++;
		i2++;
	}
	if (!is_end(line, i1) || !is_end(line, i2))
		return (0);
	return (1);
}

void	print_val(char *line, int index)
{
	while (line[index] != '\n' && line[index] != '\0')
	{
		write(1, &line[index], 1);
		index++;
	}
	write(1, "\n", 1);
}


void	search(t_table *table, char *line, int key)
{
	int		index;
	t_entry	*entry;

	index = hash(line, key, table->size);
	entry = (table->entry)[index];
	while (entry)
	{
		if (ft_strcmp(line, entry->key, key))
		{
			fill_buff(table, line, entry->val);
			return ;
		}
		entry = entry->next;
	}
	fill_buff_not_found(table, line, key);
}

void	free_all(t_table *table, char *line)
{
	int		i;
	t_entry *current;
	t_entry *temp;

	i = 0;
	while (i < table->size)
	{
		current = (table->entry)[i];
		while (current)
		{
			temp = current->next;
			free(current);
			current = temp;
		}
		i++;
	}
	free(table->entry);
	free(line);
}

int		check_end_store(char *line, int i)
{
	if (line[i - 1] == '\0')
		return (0);
	if (line[i] == '\n')
		return (0);
	return (1);
}

void	store_phase(t_table *table, char *line, int *i)
{
	int		key;
	int		value;

	key = *i;
	while (line[*i] != '\n' && line[*i] != '\0')
		(*i)++;
	(*i)++;
	value = *i;
	if (!check_end_store(line, *i))
		return ;
	store(table, line, key, value);
	while (check_end_store(line, *i))
	{
		while (line[*i] != '\n' && line[*i] != '\0')
			(*i)++;
		(*i)++;
		key = *i;
		if (!check_end_store(line, *i))
			return ;
		while (line[*i] != '\n' && line[*i] != '\0')
			(*i)++;
		(*i)++;
		value = *i;
		if (!check_end_store(line, *i))
			return ;
		store(table, line, key, value);
	}
}

int		check_end_search(char *line, int i)
{
	if (line[i - 1] == '\0')
		return (0);
	if (line[i] == '\0')
		return (0);
	return (1);
}

void	search_phase(t_table *table, char *line, int *i)
{
	int		key;
	int		j;
	
	j = 0;
	while (check_end_search(line, *i))
	{
		while (line[*i] != '\n' && line[*i] != '\0')
			(*i)++;
		(*i)++;
		key = (*i);
		if (!check_end_search(line, *i))
			return ;
		search(table, line, key);
	}
}

int		main(void)
{
	t_table	table;
	int		entry_nb;
	char	*line;
	int		i;

	entry_nb = fill_line(&line);
	if (!allocate_table(&table, entry_nb))
		return (1);
	i = 0;
	store_phase(&table, line, &i);
	search_phase(&table, line, &i);
	write(1, table.buff, table.index_buff);
	free_all(&table, line);
	return (0);
}
