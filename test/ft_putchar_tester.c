/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_tester.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:15:01 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/11 17:23:59 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftasm_checker.h"

int		ft_putchar_test(int c, int fdin)
{
	char	buffer[4096];
	char	buffer2[4096];
	int		ret;
	int		ret2;

///	dprintf(2, "processing '%s'...\n", str);

	ft_putchar(c);
	if ((ret = read(fdin, buffer, 4095)) >= 0)
		buffer[ret] = 0;
	else
	{
		dprintf(2, "read error\n");
		return (1);
	}
	write(1, &c, 1);
	if ((ret2 = read(fdin, buffer2, 4095)) >= 0)
		buffer2[ret2] = 0;
	else
	{
		dprintf(2, "read error\n");
		return (1);
	}
	if (strcmp(buffer, buffer2) != 0)
	{
		if (g_verbose)
		{
			dprintf(2, "putchar error on __%c (%d)__\n", c, c);
			ft_compare_strings(buffer, buffer2);
		}
		return (1);
	}
	return (0);
}

int		ft_putchar_tester(void)
{
	int		fds[2];
	int		c;

	pipe(fds);
	dup2(fds[1], 1);
	c = 0;
	while (c <= 1000)
	{
		if (ft_putchar_test(c, fds[0]))
			return (1);
		c++;
	}
	return (0);
}
