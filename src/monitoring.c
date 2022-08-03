/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:01:42 by aminoru-          #+#    #+#             */
/*   Updated: 2022/08/03 01:58:33 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitoring.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		db_monit();
	else if (argc == 2 && !ft_strncmp(argv[1], "--simplify", 10))
		system("cat log/monitoring.log | grep Monitoring:");
	else
		perror_error("Invalid Arguments\n");
	return (0);
}
