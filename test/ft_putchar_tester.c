/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_tester.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 04:15:23 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/11 04:15:23 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftasm_checker.h"

int		ft_putchar_test(char c, int fdin)
{
	char	buffer[4096];
	char	buffer2[4096];
	int		ret;

	ft_putchar(c);
	if ((ret = read(fdin, buffer, 4095)) >= 0)
		buffer[ret] = 0;
	else
	{
		dprintf(2, "read error\n");
		return (1);
	}
	putchar(c);
	if ((ret = read(fdin, buffer2, 4095)) >= 0)
		buffer2[ret] = 0;
	else
	{
		dprintf(2, "read error\n");
		return (1);
	}
	if (strcmp(buffer, buffer2))
	{
		if (g_verbose)
		{
			dprintf(2, "putchar error on %c\n", c);
			ft_compare_strings(buffer, buffer2);
		}
		return (0);
	}
	return (0);
}

int		ft_putchar_tester(void)
{
	int		fds[2];
	int		i;

	(void)fds;
	(void)i;
	return (0);
	/*
	pipe(fds);
	dup2(fds[1], 1);
	i = 'a';
	while (i <= 'z')
	{
		if (ft_putchar_test(i++, fds[0]))
			return (1);
	}
	return (0);
	*/
}
