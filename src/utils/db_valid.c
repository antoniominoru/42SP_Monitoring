/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:53:29 by aminoru-          #+#    #+#             */
/*   Updated: 2022/07/30 19:58:54 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/monitoring.h"

int	db_valid(t_list	*list)
{
	t_list	*next;
	char	**teste;
	int		n_words;
	int		error;

	next = list;
	error = -1;
	while (ft_lstsize(next))
	{
		n_words = ft_cont_words(next->content, '\t');
		teste = ft_split(next->content, '\t');
		if (!ft_strncmp(teste[1], "HTTP", ft_strlen(teste[1])) && n_words == 6)
			error = 0;
		if (!ft_strncmp(teste[1], "PING", ft_strlen(teste[1])) && n_words == 4)
			error = 0;
		if (!ft_strncmp(teste[1], "DNS", ft_strlen(teste[1])) && n_words == 5)
			error = 0;
		next = next->next;
	}
	return (error);
}
