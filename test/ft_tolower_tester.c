/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_tester.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 04:53:31 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/04 04:53:31 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftasm_checker.h"

int		ft_tolower_tester(void)
{
	int i;
	int mine;
	int original;

	i = -10000;
	while (i < 10000)
	{
		mine = ft_tolower(i);
		original = tolower(i);
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
