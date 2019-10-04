/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_tester.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 04:29:56 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/04 04:29:56 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftasm_checker.h"

int		ft_isascii_tester(void)
{
	int i;
	int mine;
	int original;

	i = -10000;
	while (i < 10000)
	{
		mine = ft_isascii(i);
		original = isascii(i);
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
