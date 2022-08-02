/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 22:47:38 by aminoru-          #+#    #+#             */
/*   Updated: 2022/08/02 23:16:25 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitoring.h"

void	free_moni(t_list *list)
{
	t_list	*current;

	current = list;
	while (current->next != NULL)
	{
		list = list->next;
		free(current);
		current = list;
	}
	free(current);
}
