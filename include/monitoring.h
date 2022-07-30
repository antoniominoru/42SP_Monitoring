/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:02:17 by aminoru-          #+#    #+#             */
/*   Updated: 2022/07/30 21:32:58 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITORING_H
# define MONITORING_H

# include <fcntl.h>
// lib of 42 projects
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line.h"
# include "../lib/printf/ft_printf.h"

t_list	*db_load(char *name_db);
int		db_valid(t_list	*list);
void	perror_error(char *msg);

#endif
