/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_protocol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 23:17:20 by aminoru-          #+#    #+#             */
/*   Updated: 2022/08/03 01:34:12 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitoring.h"

void	http_select(char **list)
{
	char *cmd[6];

	cmd[0] = ft_strjoin("curl --head -s ",ft_strjoin(list[2], " 2>&1"));
	cmd[1] = " | sed '$d'";
	cmd[2] = ft_strjoin(" | sed \"1s/^/Monitoramento: ",ft_strjoin(list[0], " /\""));
	cmd[3] = ft_strjoin(" | tee -a ", LOG_MON);
	cmd[4] = " | grep Monitoramento:";
	cmd[5] = ft_strjoin(cmd[0], ft_strjoin(cmd[1], ft_strjoin(cmd[2], ft_strjoin(cmd[3],cmd[4]))));
	system(cmd[5]);
	// system("curl --head -s intra.42.fr 2>&1 | sed '$d' | sed \"1s/^/Monitoramento: HTTP /\" | tee -a log/monitoring.log | grep Monitoramento:");
	system("echo ---------------- >> log/monitoring.log");
}

void	ping_select(char **list)
{
	char *cmd[6];

	cmd[0] = ft_strjoin("ping -c1 ",ft_strjoin(list[2], " 2>&1"));
	cmd[1] = " | sed '/^$/d'";
	cmd[2] = ft_strjoin(" | sed \"2s/^/Monitoramento: ",ft_strjoin(list[0], " /\""));
	cmd[3] = ft_strjoin(" | tee -a ", LOG_MON);
	cmd[4] = " | grep Monitoramento:";
	cmd[5] = ft_strjoin(cmd[0], ft_strjoin(cmd[1], ft_strjoin(cmd[2], ft_strjoin(cmd[3],cmd[4]))));
	system(cmd[5]);
	// system("ping -c1 intra.42.fr 2>&1 | sed '/^$/d'| sed \"2s/^/Monitoramento: PING /\" | tee -a log/monitoring.log | grep Monitoramento:");
	system("echo ---------------- >> log/monitoring.log");
}

void	dns_select(char **list)
{
	char *cmd[6];

	cmd[0] = ft_strjoin("nslookup ",ft_strjoin(list[2], ft_strjoin(list[4]," 2>&1")));
	cmd[1] = " | sed '/^$/d'";
	cmd[2] = ft_strjoin(" | sed \"3s/^/Monitoramento: ",ft_strjoin(list[0], " /\""));
	cmd[3] = ft_strjoin(" | tee -a ", LOG_MON);
	cmd[4] = " | grep Monitoramento:";
	cmd[5] = ft_strjoin(cmd[0], ft_strjoin(cmd[1], ft_strjoin(cmd[2], ft_strjoin(cmd[3],cmd[4]))));
	system(cmd[5]);
	// system("nslookup intra.42.fr 8.8.8.8 2>&1 | sed '/^$/d'| sed \"1s/^/Monitoramento: DNS /\" | tee -a log/monitoring.log | grep Monitoramento:");
	system("echo ---------------- >> log/monitoring.log");
}
