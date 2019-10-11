/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ_tester.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:02:58 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/11 18:15:06 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftasm_checker.h"

int		ft_strequ_tester(void)
{
	if (ft_strequ("", "dodod"))
		return (1);
	if (ft_strequ("do", "dodod"))
		return (1);
	if (ft_strequ("do", "doK"))
		return (1);
	if (ft_strequ("dodododod", "zboulex"))
		return (1);
	if (!ft_strequ("dodod", "dodod"))
		return (1);
	if (!ft_strequ("", ""))
		return (1);
	if (!ft_strequ("OUAI", "OUAI"))
		return (1);
	return (0);
}
