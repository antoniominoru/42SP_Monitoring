/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer_select.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:25:44 by aminoru-          #+#    #+#             */
/*   Updated: 2022/08/01 23:08:27 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitoring.h"

void	timer_selected(t_list *list, int timer, char **envp)
{
	t_list	*temp;
	char	**teste;
	int		n_words;

	temp = list;
	if (envp == NULL)
		ft_printf("Error");
	while (ft_lstsize(temp))
	{
		n_words = ft_cont_words(temp->content, '\t');
		teste = ft_split(temp->content, '\t');
		if (!ft_strncmp(teste[1], "HTTP", ft_strlen(teste[1])))
			if (timer % ft_atoi(teste[n_words - 1]) == 0)
			{
				ft_printf("%s----HTTP\n", teste[0]);
				pipex(ft_strjoin("curl -is ",teste[2]), "tee -a log/monitoring.log", envp, LOG_MON);
			}	
		if (!ft_strncmp(teste[1], "PING", ft_strlen(teste[1])))
			if (timer % ft_atoi(teste[n_words - 1]) == 0)
				ft_printf("PING-----%s-----%s\n", teste[1], teste[0]);
		if (!ft_strncmp(teste[1], "DNS", ft_strlen(teste[1])))
			if (timer % ft_atoi(teste[n_words - 2]) == 0)
				ft_printf("DNS-----%s-----%s\n", teste[1], teste[0]);
		temp = temp->next;
	}
}
