/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_tester.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 00:26:34 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/05 00:26:34 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftasm_checker.h"

int     ft_memcpy_tester(void)
{
	char buff[10000];
	char buff2[10000];

	ft_memcpy(buff, buff2, 10000);
	if (memcmp(buff, buff2, 10000))
		return (1);
	return (0);
}
