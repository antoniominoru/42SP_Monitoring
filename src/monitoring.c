/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:01:42 by aminoru-          #+#    #+#             */
/*   Updated: 2022/07/30 22:42:56 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitoring.h"

int	main(void)
{
	t_list	*list;

	list = db_load("db/monitoring.db");
	if (db_valid(list) == -1)
		perror_error("Error sintax db.\n");
	return (0);
}
