/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:02:17 by aminoru-          #+#    #+#             */
/*   Updated: 2022/08/01 21:11:51 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITORING_H
# define MONITORING_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
// lib of 42 projects
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line.h"
# include "../lib/printf/ft_printf.h"
# include "../lib/pipex/pipex.h"

# define HOUR_TO_SEC 86401
# define DIR_MON "db/monitoring.db"
# define LOG_MON "log/monitoring.log"

t_list	*db_load(char *name_db);
int		db_valid(t_list	*list);
void	perror_error(char *msg);
void	timer_selected(t_list *list, int timer, char **envp);

#endif
