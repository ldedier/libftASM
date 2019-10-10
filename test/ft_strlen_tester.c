/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_tester.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:02:58 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/10 18:41:12 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftasm_checker.h"

int		strlen_test(int i)
{
	int		my_strlen;
	int		true_strlen;
	char	*str;

	i = 19;

	str = ft_strnew(i);
	if (i > 0)
		memset(str, 'a', i);
	str[i] = 0;
	my_strlen = ft_strlen(str);
	true_strlen = strlen(str);
	if (my_strlen != true_strlen)
	{
		if (g_verbose)
		{
			dprintf(2, "for i = %d\n:", i);
			ft_compare_integers(my_strlen, true_strlen);
		}
		free(str);
		return (1);
	}
	free(str);
	return (0);
}

int		ft_strlen_tester(void)
{
	int i;

	i = 0;
	while (i < 1000)
	{
		if (strlen_test(i))
			return (1);
		i++;
	}
	return (0);
}
