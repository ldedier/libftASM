/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_tester.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 02:07:47 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/31 13:56:00 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftasm_checker.h"

int test_strcmp(char *s1, char *s2)
{
	int mine;
	int original;

	mine = ft_strcmp(s1, s2);
	original = strcmp(s1, s2);

//	dprintf(2, "%s %s => %d %d\n", s1, s2, mine, original);
	if (mine != original)
	{
		dprintf(2, "strcmp error for __%s__, __%s__\n", s1, s2);
		ft_compare_integers(mine, original);
		return (1);
	}
	return (0);
}

int		ft_strcmp_tester(void)
{
	if (test_strcmp("dadada", "dadada"))
		return (1);
	if (test_strcmp("", "dodod"))
		return (1);
	if (test_strcmp("do", "dodod"))
		return (1);
	if (test_strcmp("do", "doK"))
		return (1);
	if (test_strcmp("dodododod", "zboulex"))
		return (1);
	if (test_strcmp("dodod", "dodod"))
		return (1);
	if (test_strcmp("", ""))
		return (1);
	if (test_strcmp("OUAI", "OUAI"))
		return (1);
	return (0);
}
