/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_tester.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:02:58 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/06 10:52:50 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftasm_checker.h"

int		ft_strdup_tester(void)
{
	char *str1;
	char *str2;

	str1 = ft_strdup(TEST_STR);
	str2 = strdup(TEST_STR);
	if (strcmp(str1, str2))
	{
		free(str1);
		free(str2);
		return (1);
	}
	free(str1);
	free(str2);
	return (0);
}
