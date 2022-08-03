/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_monit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:25:56 by aminoru-          #+#    #+#             */
/*   Updated: 2022/08/03 01:49:06 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitoring.h"

void	db_monit(void)
{
	t_list	*list;
	int		timer;

	list = db_load(DIR_MON);
	if (db_valid(list) == -1)
	{
		free_moni(list);
		perror_error("Error sintax db.\n");
	}
	timer = 0;
	while (timer++ < HOUR_TO_SEC)
	{
		timer_selected(list, timer);
		if (timer == HOUR_TO_SEC)
			timer = 0;
		sleep(1);
	}
	free(list);
}
