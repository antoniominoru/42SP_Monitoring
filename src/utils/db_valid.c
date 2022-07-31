/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:53:29 by aminoru-          #+#    #+#             */
/*   Updated: 2022/07/31 17:55:17 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitoring.h"

int	name_valid(t_list *list);
int	len_arg_valid(t_list *list);

int	db_valid(t_list	*list)
{
	if (name_valid(list) == -1)
		return (-1);
	if (len_arg_valid(list) == -1)
		return (-1);
	return (0);
}

int	name_valid(t_list *list)
{
	t_list	*next;
	char	**teste;

	next = list;
	while (ft_lstsize(next))
	{
		teste = ft_split(next->content, '\t');
		if (!ft_strncmp(teste[1], "HTTP", 4))
			next = next->next;
		else if (!ft_strncmp(teste[1], "PING", 4))
			next = next->next;
		else if (!ft_strncmp(teste[1], "DNS", 3))
			next = next->next;
		else
			return (-1);
	}
	return (0);
}

int	len_arg_valid(t_list	*list)
{
	t_list	*next;
	char	**teste;
	int		n_words;

	next = list;
	while (ft_lstsize(next))
	{
		n_words = ft_cont_words(next->content, '\t');
		teste = ft_split(next->content, '\t');
		if (!ft_strncmp(teste[1], "HTTP", 4) && n_words != 6)
			return (-1);
		if (!ft_strncmp(teste[1], "PING", 4) && n_words != 4)
			return (-1);
		if (!ft_strncmp(teste[1], "DNS", 3) && n_words != 5)
			return (-1);
		next = next->next;
	}
	return (0);
}
