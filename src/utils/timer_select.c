/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer_select.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:25:44 by aminoru-          #+#    #+#             */
/*   Updated: 2022/08/02 21:28:00 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitoring.h"
#include <stdlib.h>

void	timer_selected(t_list *list, int timer)
{
	t_list	*temp;
	char	**teste;
	int		n_words;

	temp = list;
	while (ft_lstsize(temp))
	{
		n_words = ft_cont_words(temp->content, '\t');
		teste = ft_split(temp->content, '\t');
		if (!ft_strncmp(teste[1], "HTTP", ft_strlen(teste[1])))
			if (timer % ft_atoi(teste[n_words - 1]) == 0)
			{
				system("curl --head -s intra.42.fr 2>&1 | sed '$d' | sed \"1s/^/Monitoramento: HTTP /\" | tee -a log/monitoring.log | grep Monitoramento:");
				system("echo ---------------- >> log/monitoring.log");
			}
		if (!ft_strncmp(teste[1], "PING", ft_strlen(teste[1])))
			if (timer % ft_atoi(teste[n_words - 1]) == 0)
			{
				system("ping -c1 intra.42.fr 2>&1 | sed '/^$/d'| sed \"2s/^/Monitoramento: PING /\" | tee -a log/monitoring.log | grep Monitoramento:");
				system("echo ---------------- >> log/monitoring.log");
			}
		if (!ft_strncmp(teste[1], "DNS", ft_strlen(teste[1])))
			if (timer % ft_atoi(teste[n_words - 2]) == 0)
			{
				system("nslookup intra.42.fr 8.8.8.8 2>&1 | sed '/^$/d'| sed \"1s/^/Monitoramento: DNS /\" | tee -a log/monitoring.log | grep Monitoramento:");
				system("echo ---------------- >> log/monitoring.log");
			}
		temp = temp->next;
	}
}
