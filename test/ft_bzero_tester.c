/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_tester.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:02:58 by ldedier           #+#    #+#             */
/*   Updated: 2019/03/28 11:02:58 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftasm_checker.h"



int		test_bzero(int n)
{
	char	*str;
	int		i;

	str = (char *)malloc(n);
	memset(str, 'X', n);
	ft_bzero(str, n);
	i = 0;
	while (i < n)
	{
		if (str[i] != 0)
		{
			free(str);
			return (1);
		}
		i++;
	}
	free(str);
	return (0);
}

int		ft_bzero_tester(void)
{
	int		i;

	i = 0;
	while (i < 1000)
	{
		if (test_bzero(i))
			return (1);
		i++;
	}
	return (0);
}
