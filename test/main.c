/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:33:39 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/10 19:41:30 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftasm_checker.h"

int g_verbose = 1;
int g_asynchronous = 1;
//char *totest = "strcat";
char *totest = NULL;

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
	{"cat", &ft_cat_tester},
	//bonus
	{"strcpy", &ft_strcpy_tester},
	{"putchar", &ft_putchar_tester},
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
	int status;

	ret = 0;
	success = 0;
	i = 0;
	while (i < NB_FUNCTIONS)
	{
		if (!totest || (totest && !strcmp(g_funcs[i].name, totest)))
		{
			if (g_asynchronous)
			{
				status = process_test(i);
				printf("%s:%.*s", g_funcs[i].name, (int)((3 - 
								(strlen(g_funcs[i].name) + 1) / 8)), "\t\t\t\t\t\t\t");
				ret |= process_exit_status(status, &success);
			}
			else
			{
				status = g_funcs[i].func();
				printf("%s:%.*s", g_funcs[i].name, (int)((3 - 
								(strlen(g_funcs[i].name) + 1) / 8)), "\t\t\t\t\t\t\t");
				if (status)
				{
					printf("KO");
				}
				else
				{
					printf("OK");
					success++;
				}
			}
		}
		printf("\n");
		i++;
	}
	printf("\npassed %d / %d tests !\n", success, NB_FUNCTIONS);
	ft_strcmp("dqdqw", "dsad");
	printf("hehe\n");
	return (ret);
}
