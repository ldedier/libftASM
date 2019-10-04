/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_tester.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 01:31:39 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/04 01:31:39 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftasm_checker.h"

int		ft_isdigit_tester(void)
{
	int i;
	int mine;
	int original;

	i = -10000;
	while (i < 10000)
	{
		mine = ft_isdigit(i);
		original = isdigit(i);
		if (mine != original)
		{
			if (g_verbose)
			{
				dprintf(2, "for: %c (%d):\n", i, i);
				ft_compare_integers(mine, original);
			}
			return (1);
		}
		i++;
	}
	return (0);
}
