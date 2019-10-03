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

	i = 0;
	while (i < 1000)
	{
		if (ft_isdigit(i) != isdigit(i))
			return (1);
		i++;
	}
	return (0);
}
