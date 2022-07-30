/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:12:56 by aminoru-          #+#    #+#             */
/*   Updated: 2022/07/30 22:41:47 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitoring.h"

int		open_db(char *name_db);
t_list	*read_db(int fd);

t_list	*db_load(char *name_db)
{
	int		fd;
	t_list	*lines;

	fd = open_db(name_db);
	lines = read_db(fd);
	return (lines);
}

int	open_db(char *name_db)
{
	size_t	nlen;
	int		fd;

	nlen = ft_strlen(name_db);
	if (ft_strncmp(&name_db[nlen -3], ".db", 3))
		perror_error("Error\nWrong file extension.\n");
	fd = open(name_db, O_RDONLY);
	if (fd == -1)
		perror_error("Error\nUnable to open file.\n");
	return (fd);
}

t_list	*read_db(int fd)
{
	t_list		*list;
	t_list		*current;
	char		*gnl;

	gnl = get_next_line(fd);
	if (!gnl)
		perror_error("Error\nEmpty file\n");
	list = malloc(sizeof(t_list));
	list->content = gnl;
	current = list;
	while (gnl)
	{
		gnl = get_next_line(fd);
		if (gnl == NULL)
			return (list);
		current->next = malloc(sizeof(t_list));
		current = current->next;
		current->content = gnl;
	}
	return (list);
}
