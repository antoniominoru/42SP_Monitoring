/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:01:42 by aminoru-          #+#    #+#             */
/*   Updated: 2022/08/01 21:11:46 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitoring.h"

int	main(int argc, char **argv, char **envp)
{
	t_list	*list;
	int		timer;

	if (argc == 1)
		ft_printf("%s\n",argv[0]);
	list = db_load(DIR_MON);
	if (db_valid(list) == -1)
		perror_error("Error sintax db.\n");
	timer = 0;
	while (timer++ < HOUR_TO_SEC)
	{
		ft_printf("second %d\n", timer);
		timer_selected(list, timer, envp);
		if (timer == HOUR_TO_SEC)
			timer = 0;
		sleep(1);
	}
	return (0);
}
