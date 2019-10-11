/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:38:17 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/11 16:10:42 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftasm.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

//	ft_puts("tamer en string hehehe");
	int fd = open("auteur", O_RDONLY);
	ft_cat(0);
//	int len = ft_strlen("20000");
	return (0);
}
