/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:12:56 by aminoru-          #+#    #+#             */
/*   Updated: 2022/07/30 20:10:47 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitoring.h"

int		open_db(char *name_db);
t_list	*read_db(int fd);
void	perror_exit(char *msg, t_list *list, t_list *last);

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
	{
		ft_printf("Error\nWrong file extension.\n");
		exit(1);
	}
	fd = open(name_db, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nUnable to open given map file.\n");
		exit(1);
	}
	return (fd);
}

t_list	*read_db(int fd)
{
	t_list		*list;
	t_list		*current;

	list = malloc(sizeof(t_list));
	list->content = get_next_line(fd);
	if (!list->content)
		perror_exit("Empty db.", list, list);
	current = list;
	// while (current->content)
	// {
	// 	current->next = malloc(sizeof(t_list));
	// 	current = current->next;
	// 	current->content = get_next_line(fd);
	// }
	return (list);
}

void	perror_exit(char *msg, t_list *list, t_list *last)
{
	t_list	*current;

	perror(msg);
	current = list;
	while (current != last)
	{
		list = list->next;
		free(current->content);
		free(current);
		current = list;
	}
	free(current->content);
	free(current);
	exit(1);
}
