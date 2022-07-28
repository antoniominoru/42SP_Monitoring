/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:53:44 by aminoru-          #+#    #+#             */
/*   Updated: 2022/04/28 00:09:53 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "minunit.h"
#include "../libft.h"

int tests_run = 0;

static char *test_ft_isalpha(void)
{
	int	i;

	i = -1;
	while(++i < 250)
	{
		mu_assert("ERROR: ft_isalpha()", (ft_isalpha(i) != 0) == (isalpha(i) != 0));
	}
	return (0);
}

static char *test_ft_isdigit(void)
{
	int	i;

	i = -1;
	while(++i < 250)
	{
		mu_assert("ERROR: ft_isdigit()", (ft_isdigit(i) != 0) == (isdigit(i) != 0));
	}
	return (0);
}

static char *test_ft_isalnum(void)
{
	int	i;

	i = -1;
	while(++i < 250)
	{
		mu_assert("ERROR: ft_isalnum()", (ft_isalnum(i) != 0) == (isalnum(i) != 0));
	}	
	return (0);
}

static char *test_ft_isascii(void)
{
	int	i;

	i = -1;
	while(++i < 250)
	{
		mu_assert("ERROR: ft_isascii()", (ft_isascii(i) != 0) == (isascii(i) != 0));
	}	
	return (0);
}

static char *test_ft_isprint(void)
{
	int	i;

	i = -1;
	while(++i < 250)
	{
		mu_assert("ERROR: ft_isprint()", (ft_isprint(i) != 0) == (isprint(i) != 0));
	}	
	return (0);
}

static char *test_ft_strlen(void)
{
	mu_assert("ERROR: ft_strlen()", ft_strlen("teste_letras") == strlen("teste_letras"));	
	mu_assert("ERROR: ft_strlen()", ft_strlen("fandando") == strlen("fandando"));
	mu_assert("ERROR: ft_strlen()", ft_strlen("dasiujgjh") == strlen("dasiujgjh"));
	mu_assert("ERROR: ft_strlen()", ft_strlen("tes__") == strlen("tes__"));
	mu_assert("ERROR: ft_strlen()", ft_strlen("t*ste") == strlen("t*ste"));
	mu_assert("ERROR: ft_strlen()", ft_strlen("tefasdfasste") == strlen("tefasdfasste"));
	return (0);
}

static char *test_ft_memset(void)
{
	char	mem1[10];
	char	mem2[10];

	ft_memset(mem1, '-', 5);
	memset(mem2, '-', 5);
	mu_assert("ERROR: ft_memset() -- ref: 5",  strncmp(mem1, mem2, 10) );	
	return (0);
}

static char *test_ft_bzero(void)
{
	char	mem1[15];
	char	mem2[15];
	int		i;

	i = 15;
	ft_bzero(mem1, i);
	bzero(mem2, i);
	while (i--)
		mu_assert("ERROR: ft_bzero() -- ref: 15", mem1[i] == mem2[i]);	
	return (0);
}

static char *test_ft_memcpy(void)
{
	const char str[80] = "abcdefghijkl";
	char	buff1[80];
	char	buff2[80];
	char	*p_buff1;
	char	*p_buff2;
	int		i;

	i = -1;
	p_buff1 = ft_memcpy(buff1, str, 12);
	p_buff2 = memcpy(buff2, str, 12);
	while (++i < 12)
		mu_assert("ERROR: ft_memcpy() -- ref: 12", p_buff1[i] == p_buff2[i]);	
	return (0);
}

static char *test_ft_memmove(void)
{
	char 	str[80];
	char	*p_buff1;
	char	*p_buff2;

	memcpy(str + 20, "AHJFIUYGHJDK", 10);
	p_buff1 = ft_memmove(str + 30, str, 5);
	p_buff2 = memmove(str + 30, str, 5);
	mu_assert("ERROR: ft_memmove() -- ref: 12", !strncmp(p_buff1, p_buff2, 80));
	return (0);
}

static char *test_ft_strlcpy(void)
{
	char 	*dest;

	dest = malloc(15);
	mu_assert("ERROR: ft_strlcpy() -- size: 2", (int)ft_strlcpy(dest, "B", 2) == 1);
	mu_assert("ERROR: ft_strlcpy not assigning to pointer", !strcmp(dest, "B"));
	mu_assert("ERROR: ft_strlcpy() -- size: 0", (int)ft_strlcpy(dest, "Copiou", 0) == 6);
	mu_assert("ERROR: ft_strlcpy() -- size: 1", (int)ft_strlcpy(dest, "Copiou", 1) == 6);
	mu_assert("ERROR: ft_strlcpy not assigning to pointer", !strcmp(dest, ""));
	mu_assert("ERROR: ft_strlcpy() -- size: 4", (int)ft_strlcpy(dest, "Copiou", 4) == 6);
	mu_assert("ERROR: ft_strlcpy not assigning to pointer", !strcmp(dest, "Cop"));
	mu_assert("ERROR: ft_strlcpy() -- size: 6", (int)ft_strlcpy(dest, "Copiou", 7) == 6);
	mu_assert("ERROR: ft_strlcpy not assigning to pointer", !strcmp(dest, "Copiou"));
	mu_assert("ERROR: ft_strlcpy() -- size: 12", (int)ft_strlcpy(dest, "Copiou", 12) == 6);
	mu_assert("ERROR: ft_strlcpy not assigning to pointer", !strcmp(dest, "Copiou"));
	free(dest);
	return (0);
}

static char *test_ft_strlcat(void)
{
	char 	*dest;

	dest = malloc(15);
	ft_strlcpy(dest,"Sao ",5);
	mu_assert("ERROR: ft_strlcat() -- size: 0", (int)ft_strlcat(dest, "Paulo", 0) == 5);
	ft_strlcat(dest, "Paulo", 0);
	mu_assert("ERROR: ft_strlcpy not assigning to pointer", !strcmp(dest, "Sao "));
	mu_assert("ERROR: ft_strlcat() -- size: 9", (int)ft_strlcat(dest, "Paulo", 10) == 9);
	ft_strlcat(dest, "Paulo", 10);
	mu_assert("ERROR: ft_strlcpy not assigning to pointer", !strcmp(dest, "Sao Paulo"));
	free(dest);
	return (0);
}

static char *test_ft_toupper(void)
{
	mu_assert("ERROR: ft_toupper()", ft_toupper('t') == toupper('t'));
	mu_assert("ERROR: ft_toupper()", ft_toupper('E') == toupper('E'));
	mu_assert("ERROR: ft_toupper()", ft_toupper('_') == toupper('_'));
	return (0);
}

static char *test_ft_tolower(void)
{
	mu_assert("ERROR: ft_tolower()", ft_tolower('t') == tolower('t'));
	mu_assert("ERROR: ft_tolower()", ft_tolower('E') == tolower('E'));
	mu_assert("ERROR: ft_tolower()", ft_tolower('_') == tolower('_'));
	return (0);
}

static char *test_ft_strchr(void)
{
	mu_assert("ERROR: ft_strchr()", ft_strchr("teste", 't') == strchr("teste", 't'));
	mu_assert("ERROR: ft_strchr()", ft_strchr("testE", 'E') == strchr("testE", 'E'));
	mu_assert("ERROR: ft_strchr()", ft_strchr("TesTe", 'T') == strchr("TesTe", 'T'));
	return (0);
}

static char *test_ft_strrchr(void)
{
	mu_assert("ERROR: ft_strrchr()", ft_strrchr("teste", 't') == strrchr("teste", 't'));
	mu_assert("ERROR: ft_strrchr()", ft_strrchr("testE", 'E') == strrchr("testE", 'E'));
	mu_assert("ERROR: ft_strrchr()", ft_strrchr("TesTe", 'T') == strrchr("TesTe", 'T'));
	return (0);
}

static char *test_ft_strncmp(void)
{
	mu_assert("ERROR: ft_strncmp()", ft_strncmp("teste", "testE", 3) == strncmp("teste", "testE", 3));
	mu_assert("ERROR: ft_strncmp()", ft_strncmp("teste", "testE", 2) == strncmp("teste", "testE", 2));
	mu_assert("ERROR: ft_strncmp()", ft_strncmp("teste", "testE", 5) == strncmp("teste", "testE", 5));
	return (0);
}

static char *test_ft_memchr(void)
{
	mu_assert("ERROR: ft_memchr()", ft_memchr("testE", 'E', 3) == memchr("testE", 'E', 3));
	mu_assert("ERROR: ft_memchr()", ft_memchr("testE", 'E', 2) == memchr("testE", 'E', 2));
	mu_assert("ERROR: ft_memchr()", ft_memchr("testE", 'E', 5) == memchr("testE", 'E', 5));
	return (0);
}

static char *test_ft_memcmp(void)
{
	mu_assert("ERROR: ft_memcmp()", ft_memcmp("testE", "testE", 3) == memcmp("testE", "testE", 3));
	mu_assert("ERROR: ft_memcmp()", ft_memcmp("testE", "testE", 2) == memcmp("testE", "testE", 2));
	mu_assert("ERROR: ft_memcmp()", ft_memcmp("testE", "testE", 5) == memcmp("testE", "testE", 5));
	return (0);
}

char	*ft_strnstr2(const char *haystack, const char *needle, size_t len)
{
	size_t h;
	size_t n;

	h = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[h] != '\0')
	{
		n = 0;
		while (haystack[h + n] == needle[n] && (h + n) < len)
		{
			if (haystack[h + n] == '\0' && needle[n] == '\0')
				return ((char *)&haystack[h]);
			n++;
		}
		if (needle[n] == '\0')
			return (( char *)haystack + h);
		h++;
	}
	return (0);
}

static char *test_ft_strnstr(void)
{
	mu_assert("ERROR: ft_strnstr()", ft_strnstr("testE", "te" , 3) == ft_strnstr2("testE", "te" , 3));
	mu_assert("ERROR: ft_strnstr()", ft_strnstr("testE", "tes" , 4) == ft_strnstr2("testE", "tes" , 4));
	mu_assert("ERROR: ft_strnstr()", ft_strnstr("testE", "test" , 3) == ft_strnstr2("testE", "test" , 3));
	return (0);
}

static char *test_ft_atoi(void)
{
	mu_assert("ERROR: ft_atoi()", ft_atoi("-45634fsfdg") == atoi("-45634fsfdg"));
	mu_assert("ERROR: ft_atoi()", ft_atoi("-45634fsfd54346") == atoi("-45634fsfd54346"));
	mu_assert("ERROR: ft_atoi()", ft_atoi("45345634fsfd54346") == atoi("45345634fsfd54346"));
	return (0);
}

static char *test_ft_calloc(void)
{
	int	* i;
	int * j;
	
	i = ft_memset(ft_calloc(5,sizeof(int)), 1, (5 * sizeof(int)));
	j = ft_memset(calloc(5,sizeof(int)), 1, (5 * sizeof(int)));
	mu_assert("ERROR: ft_calloc()", ft_strlen((char *)i) == ft_strlen((char *)j) );
	i = ft_memset(ft_calloc(5,sizeof(int)), 1, (5 * sizeof(int)));
	j = ft_memset(calloc(4,sizeof(int)), 1, (4 * sizeof(int)));
	mu_assert("ERROR: ft_calloc()", !(ft_strlen((char *)i) == ft_strlen((char *)j)) );
	return (0);
}

static char *test_ft_strdup(void)
{
	mu_assert("ERROR: ft_strdup()", !strcmp(ft_strdup("-45634fsfdg"), strdup("-45634fsfdg")));
	mu_assert("ERROR: ft_strdup()", !strcmp(ft_strdup("-45634fsfd54346"), strdup("-45634fsfd54346")));
	mu_assert("ERROR: ft_strdup()", !strcmp(ft_strdup("45345634fsfd54346"), strdup("45345634fsfd54346")));
	return (0);
}

static char *test_ft_substr(void)
{
	mu_assert("ERROR: ft_substr()", !strcmp(ft_substr("-45634fsfdg", 3, 5), "634fs"));
	mu_assert("ERROR: ft_substr()", !strcmp(ft_substr("-45634fsfd54346", 2, 6), "5634fs"));
	mu_assert("ERROR: ft_substr()", !strcmp(ft_substr("45345634fsfd54346", 5, 7), "634fsfd"));
	return (0);
}

static char *test_ft_strjoin(void)
{
	mu_assert("ERROR: ft_strjoin()", !strcmp(ft_strjoin("fdsfdg", "rewt"), "fdsfdgrewt"));
	mu_assert("ERROR: ft_strjoin()", !strcmp(ft_strjoin("fsdfasdf", "rewt"), "fsdfasdfrewt"));
	mu_assert("ERROR: ft_strjoin()", !strcmp(ft_strjoin("fdsfdg43trf", "rewfdst4t"), "fdsfdg43trfrewfdst4t"));
	return (0);
}

static char *test_ft_strtrim(void)
{
	mu_assert("ERROR: ft_strtrim()", !strncmp(ft_strtrim("   spaces  ", " "), "spaces", 7));
	mu_assert("ERROR: ft_strtrim()", !strncmp(ft_strtrim("spaces", ""), "spaces", 7));
	mu_assert("ERROR: ft_strtrim()", !strncmp(ft_strtrim("   spaces", " "), "spaces", 7));
	mu_assert("ERROR: ft_strtrim()", !strncmp(ft_strtrim("   ", " "), "", 7));
	mu_assert("ERROR: ft_strtrim()", !strncmp(ft_strtrim(" ++--- spaces++\n  ", "\n +-"), "spaces", 7));
	return (0);
}

static char	*test_ft_split(void)
{
	char *src = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";
	char *src2 = "  lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse  ";
	char **split = malloc(13 * sizeof(char *));
	split = ft_split(src, ' ');

	mu_assert("ERROR: ft_split[0]", !strcmp(split[0], "lorem"));
	mu_assert("ERROR: ft_split[1]", !strcmp(split[1], "ipsum"));
	mu_assert("ERROR: ft_split[11]", !strcmp(split[11], "Suspendisse"));
	mu_assert("ERROR: ft_split[12]", split[12] == 0);
	split = ft_split(src2, ' ');
	mu_assert("ERROR: ft_split[0]", !strcmp(split[0], "lorem"));
	mu_assert("ERROR: ft_split[1]", !strcmp(split[1], "ipsum"));
	mu_assert("ERROR: ft_split[11]", !strcmp(split[11], "Suspendisse"));
	mu_assert("ERROR: ft_split[12]", split[12] == 0);
	free(*split);
	return (0);
}

static char *test_ft_itoa(void)
{
	mu_assert("ERROR: ft_itoa(12344)", !strcmp(ft_itoa(12344), "12344"));
	mu_assert("ERROR: ft_itoa(-12344)", !strcmp(ft_itoa(-12344), "-12344"));
	mu_assert("ERROR: ft_itoa(0)", !strcmp(ft_itoa(0), "0"));
	return (0);
}

// static char *test_ft_strmapi(void)
// {
// 	return (0);
// }

// static char *test_ft_striteri(void)
// {
// 	return (0);
// }

static char *test_ft_putchar_fd(void)
{
	ft_putchar_fd('c', 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

static char *test_ft_putstr_fd(void)
{
	ft_putstr_fd("Deu Certo!!", 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

static char *test_ft_putendl_fd(void)
{
	ft_putendl_fd("Deu Certo!!", 1);
	return (0);
}

static char *test_ft_putnbr_fd(void)
{
	ft_putnbr_fd(1234, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

static char	*test_ft_lstnew(void)
{
	t_list	*obj;

	obj = ft_lstnew("List Item");
	mu_assert("ERROR: ft_lstnew() content", !strcmp(obj->content, "List Item"));
	mu_assert("ERROR: ft_lstnew() next", obj->next == NULL);
	free(obj);
	return (0);
}

static char	*test_ft_lstadd_front(void)
{
	t_list *lst1 = ft_lstnew("Previous First");
	t_list *lst2 = ft_lstnew("Second First");
	ft_lstadd_front(&lst1, lst2);
	mu_assert("ERROR: ft_lstadd_front()", lst1->content == lst2->content);
	return (0);
}

static char	*test_ft_lstsize(void)
{
	t_list *lst1 = ft_lstnew("First");
	t_list *lst2 = ft_lstnew("Second");
	t_list *lst3 = ft_lstnew("Third");
	mu_assert("ERROR: ft_lstsize single", ft_lstsize(lst1) == 1);
	ft_lstadd_front(&lst1, lst2);
	ft_lstadd_front(&lst1, lst3);
	mu_assert("ERROR: ft_lstsize", ft_lstsize(lst1) == 3);
	return (0);
}

static char *test_ft_lstlast(void)
{
	t_list *lst1 = ((void *)0);
	t_list *lst2;
	t_list *lst3;

	mu_assert("Error: ft_lstlast()", lst1 == ft_lstlast(lst1));
	lst2 = ((void *)0);
	lst3 = ft_lstlast(lst1);
	mu_assert("Error: ft_lstlast()", lst2 == lst3);
	return (0);
}

static char	*test_ft_lstadd_back(void)
{
	t_list *lst1 = ft_lstnew("First");
	t_list *lst2 = ft_lstnew("Second");
	ft_lstadd_back(&lst1, lst2);
	mu_assert("ERROR: ft_lstadd_back()", lst1->next == lst2);
	mu_assert("ERROR: ft_lstadd_back()", !strcmp(lst1->content, "First"));
	mu_assert("ERROR: ft_lstadd_back()", !strcmp(lst1->next->content, "Second"));
	return (0);
}

void	del(void *content)
{
	(void)content;
}

static char	*test_ft_lstdelone(void)
{
	t_list *lst1 = ft_lstnew("First");
	t_list *lst2 = ft_lstnew("Second");
	t_list *lst3 = ft_lstnew("Third");
	ft_lstadd_back(&lst1, lst2);
	ft_lstadd_back(&lst1, lst3);
	ft_lstdelone(lst1, del);
	return (0);
}

static char	*test_ft_lstclear(void)
{
	t_list *lst1 = ft_lstnew("First");
	t_list *lst2 = ft_lstnew("Second");
	t_list *lst3 = ft_lstnew("Third");
	ft_lstadd_back(&lst1, lst2);
	ft_lstadd_back(&lst1, lst3);
	mu_assert("ERROR: ft_lstclear", lst1);
	mu_assert("ERROR: ft_lstclear", lst1->next);
	ft_lstclear(&lst1, del);
	mu_assert("ERROR: ft_lstclear", !lst1);
	return (0);
}

// static char *test_ft_lstiter(void)
// {
// 	return (0);
// }

// static void	*increment(void *c)
// {
// 	return (c);
// }

// static char	*test_ft_lstmap(void)
// {
// 	t_list *lst1 = ft_lstnew("1");
// 	ft_lstadd_back(&lst1, ft_lstnew("2"));
// 	ft_lstadd_back(&lst1, ft_lstnew("3"));
// 	ft_lstmap(lst1, increment, del);
// 	return (0);
// }

static char *all_tests(void)
{
	mu_run_test(test_ft_isalpha);
	mu_run_test(test_ft_isdigit);
	mu_run_test(test_ft_isalnum);
	mu_run_test(test_ft_isascii);
	mu_run_test(test_ft_isprint);
	mu_run_test(test_ft_strlen);
	mu_run_test(test_ft_memset);
	mu_run_test(test_ft_bzero);
	mu_run_test(test_ft_memcpy);
	mu_run_test(test_ft_memmove);
	mu_run_test(test_ft_strlcpy);
	mu_run_test(test_ft_strlcat);
	mu_run_test(test_ft_toupper);
	mu_run_test(test_ft_tolower);
	mu_run_test(test_ft_strchr);
	mu_run_test(test_ft_strrchr);
	mu_run_test(test_ft_strncmp);
	mu_run_test(test_ft_memchr);
	mu_run_test(test_ft_memcmp);
	mu_run_test(test_ft_strnstr);
	mu_run_test(test_ft_atoi);
	mu_run_test(test_ft_calloc);
	mu_run_test(test_ft_strdup);
	mu_run_test(test_ft_substr);
	mu_run_test(test_ft_strjoin);
	mu_run_test(test_ft_strtrim);
	mu_run_test(test_ft_split);
	mu_run_test(test_ft_itoa);
	// mu_run_test(test_ft_strmapi);
	// mu_run_test(test_ft_striteri);
	mu_run_test(test_ft_putchar_fd);
	mu_run_test(test_ft_putstr_fd);
	mu_run_test(test_ft_putendl_fd);
	mu_run_test(test_ft_putnbr_fd);
	mu_run_test(test_ft_lstnew);
	mu_run_test(test_ft_lstadd_front);
	mu_run_test(test_ft_lstsize);
	mu_run_test(test_ft_lstlast);
	mu_run_test(test_ft_lstadd_back);
	mu_run_test(test_ft_lstdelone);
	mu_run_test(test_ft_lstclear);
	// mu_run_test(test_ft_lstiter);
	// mu_run_test(test_ft_lstmap);
	return (0);
}

int	main(void)
{
	char *result;

	result = all_tests();	
	if (result)
		printf("%s\n", result);
	else
		printf("All Tests Passed\n");
	printf("Test run: %d\n", tests_run);
	return (0);
}
