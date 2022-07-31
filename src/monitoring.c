/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:01:42 by aminoru-          #+#    #+#             */
/*   Updated: 2022/07/31 03:18:22 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitoring.h"

int	main(void)
{
	t_list	*list;
	int		cont;

	list = db_load("db/monitoring.db");
	if (db_valid(list) == -1)
		perror_error("Error sintax db.\n");
	cont = 0;
	while(cont++ < 86401)
	{
		if (cont % 10 == 0)
			ft_printf("HTTP-----10-----\n");
		if (cont % 15 == 0)
			ft_printf("PING-----15-----\n");
		if (cont % 21 == 0)
			ft_printf("DNS-----21-----\n");
		if (cont == 8641)
			cont = 0;
		sleep(1);
	}
	return (0);
}
