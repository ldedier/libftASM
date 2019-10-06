/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 11:36:04 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/06 11:48:37 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_cat(int fd)
{
	char buffer[20];
	int ret;
	int i = 0;

	(void)i;
	while ((ret = read(fd, buffer, 20)))
	{
		buffer[ret] = 0;
		printf("%s", buffer);
		//printf("%s (%d)", buffer, i++);
	}
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	int fd = open("Makefile", O_RDONLY);
	ft_cat(0);
	return (0);
}
