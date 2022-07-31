/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:01:42 by aminoru-          #+#    #+#             */
/*   Updated: 2022/07/31 17:22:51 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitoring.h"

int	main(void)
{
	t_list	*list;
	int		timer;

	list = db_load(DIR_MONITORING);
	if (db_valid(list) == -1)
		perror_error("Error sintax db.\n");
	timer = 0;
	while (timer++ < HOUR_TO_SEC)
	{
		timer_selected(list, timer);
		ft_printf("second %d\n", timer);
		if (timer == HOUR_TO_SEC)
			timer = 0;
		sleep(1);
	}
	return (0);
}
