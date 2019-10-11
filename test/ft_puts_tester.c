/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts_tester.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:02:58 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/10 17:52:52 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftasm_checker.h"

int		ft_puts_test(char *str, int fdin)
{
	char	buffer[4096];
	char	buffer2[4096];
	int		ret;
	int		ret2;

	dprintf(2, "processing '%s'...\n", str);

	ft_putstr(str);
	if ((ret = read(fdin, buffer, 4095)) >= 0)
		buffer[ret] = 0;
	else
	{
		dprintf(2, "read error\n");
		return (1);
	}
//	dprintf(2, "%d, %d\n", buffer[0], buffer[1]);
	printf("%s", str);
	if ((ret2 = read(fdin, buffer2, 4095)) >= 0)
		buffer2[ret2] = 0;
	else
	{
		dprintf(2, "read error\n");
		return (1);
	}
//	dprintf(2, "%d, %d\n", buffer2[0], buffer2[1]);
	if (strcmp(buffer, buffer2) != 0)
	{
		if (g_verbose)
		{
			dprintf(2, "puts error on __%s__\n", str);
			ft_compare_strings(buffer, buffer2);
		}
		return (1);
	}
	return (0);
}

int ft_puts_test_bis(char *str)
{
	(void)str;
	ft_puts(str);
	return (0);
}

int		ft_test_recur(char *str, int recur, int max_recur, int fdin)
{
	int i;

	(void)fdin;
	if (recur == max_recur)
	{
		str[recur] = 0;
	//	return (ft_puts_test(str, fdin));
		return (ft_puts_test_bis(str));
	}
	else
	{
		i = 32;
		while (i <= 126)
		{
			str[recur] = i;
			if (ft_test_recur(str, recur + 1, max_recur, fdin))
				return (1);
			i++;
		}
		return (0);
	}
}

int			ft_puts_test2(void)
{
	char *str;
	int i;

	i = 100;
	while (i < 1000)
	{
		str = strdup("salut les freres");
		//printf("%s", str);
		ft_putstr(str);
		printf("\n");
		free(str);
		i++;
	}
	return (0);
}

int		ft_puts_tester(void)
{
	int		fds[2];
	char	*str;
	int		i;

	ft_puts_test2();
	return (0);
	pipe(fds);
	dup2(fds[1], 1);
	str = ft_strnew(3);
	i = 1;
	while (i <= 2)
	{
		if (ft_test_recur(str, 0, i, fds[0]))
		{
			free(str);
			return (1);
		}
		i++;
	}
	free(str);
	return (0);
}
