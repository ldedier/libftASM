/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_tester.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:02:58 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/06 09:34:22 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftasm_checker.h"

int     ft_strcat_tester(void)
{
	char *str1;
	char *str2;

	str1 = ft_strnew(100);
	str2 = ft_strnew(100);

	strcat(str1, "salut");
	ft_strcat(str2, "salut");

	strcat(&str1[3], "okoklespotes");
	ft_strcat(&str2[3], "okoklespotes");

	strcat(&str1[10], "hehehe on strcat encore une fois haha");
	ft_strcat(&str2[10], "hehehe on strcat encore une fois haha");
	if (ft_strcmp(str1, str2))
	{
		free(str1);
		free(str2);
		return (1);
	}
	free(str1);
	free(str2);
	return (0);
}
