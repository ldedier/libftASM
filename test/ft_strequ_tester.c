/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ_tester.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 00:01:09 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/12 00:01:09 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftasm_checker.h"

int		test_strequ(char *s1, char *s2)
{
	int mine;
	int original;

	mine = ft_strequ(s1, s2);
	original = (strcmp(s1, s2) == 0);
	if (mine != original)
	{
		dprintf(2, "strequ error for __%s__, __%s__\n", s1, s2);
		ft_compare_integers(mine, original);
	//	return (1);
	}
	return (0);
}


int		ft_strequ_tester(void)
{
	if (test_strequ("", "dodod"))
		return (1);
	if (test_strequ("do", "dodod"))
		return (1);
	if (test_strequ("do", "doK"))
		return (1);
	if (test_strequ("dodododod", "zboulex"))
		return (1);
	if (test_strequ("dodod", "dodod"))
		return (1);
	if (test_strequ("", ""))
		return (1);
	if (test_strequ("OUAI", "OUAI"))
		return (1);
	return (0);
}
