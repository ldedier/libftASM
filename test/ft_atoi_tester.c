/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_tester.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:02:58 by ldedier           #+#    #+#             */
/*   Updated: 2019/03/28 11:02:58 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftasm_checker.h"

int		test_atoi(char *str)
{
	int		mine;
	int		original;

	mine = ft_atoi(str);
	original = atoi(str);
	if (mine != original)
	{
		if (g_verbose)
		{
			dprintf(2, "atoi error for %s\n", str);
			ft_compare_integers(mine, original);
		}
		return (1);
	}
	return (0);
}

int		ft_atoi_tester(void)
{
	int		i;
	char	*str;

	i = -1000;
	while (i < 10000)
	{
		str = ft_itoa(i);
		if (test_atoi(str))
		{
			free(str);
			return (1);
		}
		free(str);
		i++;
	}
	if (test_atoi("40320430505"))
		return (1);
	if (test_atoi("                 4"))
		return (1);
	if (test_atoi("                -53"))
		return (1);
	if (test_atoi("            \t\t       532"))
		return (1);
	if (test_atoi("+          	\t\t\t    5d32"))
		return (1);
	if (test_atoi("0423d55"))
		return (1);
	if (test_atoi("+-0423d55"))
		return (1);
	str = ft_itoa(INT_MIN);
	if (test_atoi("str"))
	{
		free(str);
		return (1);
	}
	str = ft_itoa(INT_MAX);
	if (test_atoi("str"))
	{
		free(str);
		return (1);
	}
	return (0);
}
