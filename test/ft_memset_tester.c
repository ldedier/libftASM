/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_tester.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 23:57:54 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/04 23:57:54 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftasm_checker.h"

int		test_memset(int n, char c)
{
	char	*str;
	int		i;

	str = (char *)malloc(n);
	ft_memset(str, c, n);
	i = 0;
	while (i < n)
	{
		if (str[i] != c)
		{
			if (g_verbose)
			{
				dprintf(2, "error on index %d"
					", len = %d for character (%c;%d) (got (%c ; %d))\n",
						i, n, c, c, str[i], str[i]);
			}
			free(str);
			return (1);
		}
		i++;
	}
	free(str);
	return (0);
}

int		ft_memset_tester(void)
{
	int		i;
	int		c;
	
	c = 0;
	i = 0;
	while (c < 100)
	{
		i = 0;
		while (i < 100)
		{
			if (test_memset(i, c))
				return (1);
			i++;
		}
		c++;
	}
	return (0);
}
