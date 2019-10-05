/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_tester.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:02:58 by ldedier           #+#    #+#             */
/*   Updated: 2019/03/28 11:02:58 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftasm_checker.h"

int     ft_strcpy_tester(void)
{
	char *str1;
	char *str2;

	str1 = ft_strnew(100);
	str2 = ft_strnew(100);

	strcpy(str1, "salut");
	ft_strcpy(str2, "salut");

	strcpy(&str1[3], "okoklespotes");
	ft_strcpy(&str2[3], "okoklespotes");
	
	strcpy(&str1[10], "hehehe on strcpy encore une fois haha");
	ft_strcpy(&str2[10], "hehehe on strcpy encore une fois haha");
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
