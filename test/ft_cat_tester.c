/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:02:58 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/06 15:17:20 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftasm_checker.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_cat_c(int fd)
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


int		ft_cat_tester(void)
{
	int fd;

	fd = open("Makefile", O_RDONLY);
	//fd = 0; 
	ft_cat(fd);
	return (0);
}
