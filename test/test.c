/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:53:44 by aminoru-          #+#    #+#             */
/*   Updated: 2022/07/31 17:50:27 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	g_tests_run = 0;

static char	*test_db_valid(void)
{
	t_list	*list;
	int		ok;

	ok = 0;
	list = ft_lstnew("intra	HTTP	intra.42.fr	GET	200	120");
	mu_assert("ERROR: db_valid()", db_valid(list) == ok);
	list = ft_lstnew("intra	HTTP	intra.42.fr	GET	200");
	mu_assert("ERROR: db_valid()", db_valid(list) != ok);
	list = ft_lstnew("game ping test	PING	game.42sp.org.br	60");
	mu_assert("ERROR: db_valid()", db_valid(list) == ok);
	list = ft_lstnew("game ping test	PING	game.42sp.org.br	60	rr");
	mu_assert("ERROR: db_valid()", db_valid(list) != ok);
	list = ft_lstnew("game ping test	DNS	game.42sp.org.br	60	tt");
	mu_assert("ERROR: db_valid()", db_valid(list) == ok);
	list = ft_lstnew("game ping test	DNS	game.42sp.org.br	60	tt	rr");
	mu_assert("ERROR: db_valid()", db_valid(list) != ok);
	list = ft_lstnew("game ping test	PIN	game.42sp.org.br	60	tt");
	mu_assert("ERROR: db_valid()", db_valid(list) != ok);
	free(list);
	return (0);
}

static char	*all_tests(void)
{
	mu_run_test(test_db_valid);
	return (0);
}

int	main(void)
{
	char	*result;

	result = all_tests();
	if (result)
		printf("%s\n", result);
	else
		printf("All Tests Passed\n");
	printf("Test run: %d\n", g_tests_run);
	return (0);
}
