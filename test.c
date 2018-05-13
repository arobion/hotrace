#include <stdlib.h>
#include <stdio.h>

typedef struct		s_entry
{
	int				key;
	int				val;
	struct s_entry	*next;
}					t_entry;

typedef struct		s_table
{
	int				size;
	struct s_entry	**entry;
}					t_table;

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
			//fill_buff(entry->val, table);
			printf("key: %d, val: %d\n", entry->key, entry->val);
			return ;
		}
		entry = entry->next;
	}
	//fill_buff_not_found(key, table);
	printf("key %d not found\n", key);
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
	//free(line);
}

int		main(void)
{
	t_table	table;
	int		entry_nb;
	char	line[] = "key1\nval1\nkey2\nval2\nkey3\nval3";

	entry_nb = 65536;
	if (!allocate_table(&table, entry_nb / 0.8))
		return (1);

	// store phase
	store(&table, line, 0, 5);
	store(&table, line, 10, 15);
	store(&table, line, 20, 25);

	// search phase
	search(&table, line, 10);
	search(&table, line, 5);
	search(&table, line, 25);
	free_all(&table, line);
	return (0);
}
