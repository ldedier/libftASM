/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:02:58 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/31 12:35:12 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftasm_checker.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_cat_c(int fd)
{
	char buffer[4096];
	int ret;

	while ((ret = read(fd, buffer, 4095)) > 0)
	{
		buffer[ret] = 0;
		printf("%s", buffer);
	}
}

int		ft_cat_test(int fdin, char *filename)
{
	char	buffer[4096];
	char	buffer2[4096];
	int		ret;
	int		fd;

	fd = open(filename, O_RDONLY);
	ft_cat(fd);
	if ((ret = read(fdin, buffer, 4095)) >= 0)
		buffer[ret] = 0;
	else
	{
		dprintf(2, "read error\n");
		return (1);
	}
	close(fd);
	fd = open(filename, O_RDONLY);
	ft_cat_c(fd);
	if ((ret = read(fdin, buffer2, 4095)) >= 0)
		buffer2[ret] = 0;
	else
	{
		dprintf(2, "read error\n");
		return (1);
	}
	close(fd);
	if (strcmp(buffer, buffer2))
	{
		if (g_verbose)
		{
			dprintf(2, "cat error on %s\n", filename);
			ft_compare_strings(buffer, buffer2);
		}
		return (1);
	}
	return (0);
}

int		ft_cat_tester(void)
{
	int		fds[2];
	int i;

	pipe(fds);
	dup2(fds[1], 1);
	i = 0;
	while (i < 1000)
	{
		if (ft_cat_test(fds[0], "Makefile"))
			return (1);
		i++;
	}
	return (0);
}
