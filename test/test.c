/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:53:44 by aminoru-          #+#    #+#             */
/*   Updated: 2022/07/31 18:20:47 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	g_tests_run = 0;

static char	*test_db_valid1(void)
{
	t_list	*list;
	int		ok;

	ok = 0;
	list = ft_lstnew("intra	HTTP	intra.42.fr	GET	200	120");
	mu_assert("ERROR: db_valid()", db_valid(list) == ok);
	list = ft_lstnew("intra	HTTP	intra.42.fr	GET	200");
	mu_assert("ERROR: db_valid()", db_valid(list) != ok);
	list = ft_lstnew("intra	HTTP	intra.42.fr	GET	200	120	tt");
	mu_assert("ERROR: db_valid()", db_valid(list) != ok);
	free(list);
	return (0);
}

static char	*test_db_valid2(void)
{
	t_list	*list;
	int		ok;

	ok = 0;
	list = ft_lstnew("game ping test	PING	game.42sp.org.br	60");
	mu_assert("ERROR: db_valid()", db_valid(list) == ok);
	list = ft_lstnew("game ping test	PING	game.42sp.org.br");
	mu_assert("ERROR: db_valid()", db_valid(list) != ok);
	list = ft_lstnew("game ping test	PING	game.42sp.org.br	60	tt");
	mu_assert("ERROR: db_valid()", db_valid(list) != ok);
	free(list);
	return (0);
}

static char	*test_db_valid3(void)
{
	t_list	*list;
	int		ok;

	ok = 0;
	list = ft_lstnew("game dns test	DNS	game.42sp.org.br	60	8.8.8.8");
	mu_assert("ERROR: db_valid()", db_valid(list) == ok);
	list = ft_lstnew("game dns test	DNS	game.42sp.org.br	60");
	mu_assert("ERROR: db_valid()", db_valid(list) != ok);
	list = ft_lstnew("game dns test	DNS	game.42sp.org.br	60	8.8.8.8	tt");
	mu_assert("ERROR: db_valid()", db_valid(list) != ok);
	free(list);
	return (0);
}

static char	*test_db_valid4(void)
{
	t_list	*list;
	int		ok;

	ok = 0;
	list = ft_lstnew("game dns test	DrS	game.42sp.org.br	60	8.8.8.8");
	mu_assert("ERROR: db_valid()", db_valid(list) != ok);
	list = ft_lstnew("game dns test	DrS	game.42sp.org.br	60");
	mu_assert("ERROR: db_valid()", db_valid(list) != ok);
	list = ft_lstnew("game dns test	DrS	game.42sp.org.br	60	8.8.8.8	tt");
	mu_assert("ERROR: db_valid()", db_valid(list) != ok);
	free(list);
	return (0);
}

static char	*test_db_valid5(void)
{
	t_list	*list;
	int		ok;

	ok = 0;
	list = ft_lstnew("game dns test	DN	game.42sp.org.br	60	8.8.8.8");
	mu_assert("ERROR: db_valid()", db_valid(list) != ok);
	list = ft_lstnew("game dns test	DN	game.42sp.org.br	60");
	mu_assert("ERROR: db_valid()", db_valid(list) != ok);
	list = ft_lstnew("game dns test	DN	game.42sp.org.br	60	8.8.8.8	tt");
	mu_assert("ERROR: db_valid()", db_valid(list) != ok);
	free(list);
	return (0);
}

static char	*all_tests(void)
{
	mu_run_test(test_db_valid1);
	mu_run_test(test_db_valid2);
	mu_run_test(test_db_valid3);
	mu_run_test(test_db_valid4);
	mu_run_test(test_db_valid5);
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
