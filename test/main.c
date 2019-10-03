/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:33:39 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/03 18:33:39 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftasm_checker.h"

t_test_func	g_funcs[NB_FUNCTIONS] = 
{
	{"bzero", &ft_bzero_tester},
	{"strcat", &ft_strcat_tester},
	{"isalpha", &ft_isalpha_tester},
	{"isdigit", &ft_isdigit_tester},
	{"isalnum", &ft_isalnum_tester},
	{"isascii", &ft_isascii_tester},
	{"isprint", &ft_isprint_tester},
	{"toupper", &ft_toupper_tester},
	{"tolower", &ft_tolower_tester},
	{"puts", &ft_puts_tester},
	{"strlen", &ft_strlen_tester},
	{"memset", &ft_memset_tester},
	{"memcpy", &ft_memcpy_tester},
	{"strdup", &ft_strdup_tester},
	{"putchar", &ft_putchar_tester},
	{"cat", &ft_cat_tester},
	{"strcpy", &ft_strcpy_tester},
	{"putendl", &ft_putendl_tester},
	{"puts_fd", &ft_puts_fd_tester},
	{"abs", &ft_abs_tester},
	{"min", &ft_min_tester},
	{"max", &ft_max_tester}
};

int main(void)
{
	int i;
	int ret;
	int success;

	ret = 0;
	success = 0;
	i = 0;
	while (i < NB_FUNCTIONS)
	{
		printf("%s:%.*s", g_funcs[i].name, (int)((3 - 
			(strlen(g_funcs[i].name) + 1) / 8)), "\t\t\t\t\t\t\t");
		if (g_funcs[i].func())
		{
			ret |= 1;
			printf("%sKO%s", RED, EOC);
		}
		else
		{
			printf("%sOK √%s", GREEN, EOC);
			success++;
		}
		printf("\n");
		i++;
	}
	printf("\npassed %d / %d tests !\n", success, NB_FUNCTIONS);
	return (ret);
}
