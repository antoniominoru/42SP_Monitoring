/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer_select.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:25:44 by aminoru-          #+#    #+#             */
/*   Updated: 2022/07/31 17:30:08 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitoring.h"

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
				ft_printf("HTTP-----%s-----%s\n", teste[1], teste[0]);
		if (!ft_strncmp(teste[1], "PING", ft_strlen(teste[1])))
			if (timer % ft_atoi(teste[n_words - 1]) == 0)
				ft_printf("PING-----%s-----%s\n", teste[1], teste[0]);
		if (!ft_strncmp(teste[1], "DNS", ft_strlen(teste[1])))
			if (timer % ft_atoi(teste[n_words - 2]) == 0)
				ft_printf("DNS-----%s-----%s\n", teste[1], teste[0]);
		temp = temp->next;
	}
}
