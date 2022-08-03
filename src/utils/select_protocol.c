/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_protocol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 23:17:20 by aminoru-          #+#    #+#             */
/*   Updated: 2022/08/03 20:24:33 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitoring.h"

void	http_select(char **list)
{
	char	*cmd[6];
	char	*tmp[3];

	cmd[0] = ft_strjoin("curl -s -I ", list[2]);
	cmd[1] = ft_strjoin(" | sed '$d'", " | sed \"1s/^/Monitoring: ");
	cmd[2] = ft_strjoin(list[0], " /\"");
	cmd[3] = ft_strjoin(" | tee -a ", LOG_MON);
	cmd[4] = " | grep Monitoring:";
	tmp[0] = ft_strjoin(cmd[0], cmd[1]);
	tmp[1] = ft_strjoin(cmd[2], cmd[3]);
	tmp[2] = ft_strjoin(tmp[0], tmp[1]);
	cmd[5] = ft_strjoin(tmp[2], cmd[4]);
	system(cmd[5]);
	system("echo ---------------- >> log/monitoring.log");
}

void	ping_select(char **list)
{
	char	*cmd[6];
	char	*tmp[3];

	cmd[0] = ft_strjoin("ping -c1 ", ft_strjoin(list[2], " 2>&1"));
	cmd[1] = ft_strjoin(" | sed '/^$/d'", " | sed \"2s/^/Monitoring: ");
	cmd[2] = ft_strjoin(list[0], " /\"");
	cmd[3] = ft_strjoin(" | tee -a ", LOG_MON);
	cmd[4] = " | grep Monitoring:";
	tmp[0] = ft_strjoin(cmd[0], cmd[1]);
	tmp[1] = ft_strjoin(cmd[2], cmd[3]);
	tmp[2] = ft_strjoin(tmp[0], tmp[1]);
	cmd[5] = ft_strjoin(tmp[2], cmd[4]);
	system(cmd[5]);
	system("echo ---------------- >> log/monitoring.log");
}

void	dns_select(char **list)
{
	char	*cmd[6];
	char	*tmp[3];

	cmd[0] = ft_strjoin("nslookup ", ft_strjoin(list[2], " "));
	cmd[1] = ft_strjoin(ft_strjoin(list[4], " 2>&1"), " | sed '/^$/d'");
	cmd[2] = ft_strjoin(" | sed \"3s/^/Monitoring: ", list[0]);
	cmd[3] = ft_strjoin(" /\"", ft_strjoin(" | tee -a ", LOG_MON));
	cmd[4] = " | grep Monitoring:";
	tmp[0] = ft_strjoin(cmd[0], cmd[1]);
	tmp[1] = ft_strjoin(cmd[2], cmd[3]);
	tmp[2] = ft_strjoin(tmp[0], tmp[1]);
	cmd[5] = ft_strjoin(tmp[2], cmd[4]);
	system(cmd[5]);
	system("echo ---------------- >> log/monitoring.log");
}
