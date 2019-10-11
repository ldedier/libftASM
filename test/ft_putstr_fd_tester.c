/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_tester.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:02:58 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/11 17:10:56 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftasm_checker.h"

int		test_putstr_fd(int fd, int fdin, int tmp_fd)
{
	char	buffer[4096];
	char	buffer2[4096];
	char	*str = strdup("pouet pouet!\n");
	int		ret;
	int		ret2;

	ft_putstr_fd(str, fd);
	if ((ret = read(fdin, buffer, 4095)))
		buffer[ret] = 0;
	write(fd, str, ft_strlen(str));
	if ((ret2 = read(fdin, buffer2, 4095)))
		buffer2[ret2] = 0;
	if (strcmp(buffer2, buffer))
	{
		dup2(tmp_fd, fd);
		dprintf(2, "putstr_fd failed on fd %d\n", fd);
		ft_compare_strings(buffer, buffer2);
		free(str);
		return (1);
	}
	free(str);
	return (0);
}

int		ft_putstr_fd_tester(void)
{
	int fd;
	int fds[2];
	int tmp_fd;

	pipe(fds);
	fd = 1;
	while (fd < 50)
	{
		if (fd == 2 || fd == fds[0] || fd == fds[1])
		{
			fd++;
			continue;
		}
		tmp_fd = dup(fd);
		dup2(fds[1], fd);
		if (test_putstr_fd(fd, fds[0], tmp_fd))
			return (1);
		dup2(tmp_fd, fd);
		fd++;
	}
	return (0);
}
