/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftasm.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 19:10:50 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/06 11:28:47 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTASM_H
# define FT_LIBFTASM_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>


void				ft_bzero(void *s, size_t n);
char				*ft_strcat(char *dest, char const *src);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_puts(char const *s);

size_t				ft_strlen(char const *s);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, void const *src, size_t n);
char				*ft_strdup(char const *s);

void				ft_cat(int fd);

int					ft_putchar(char c);
char				*ft_strcpy(char *dest, char const *src);
void				ft_putstr_fd(char const *s, int fd);
int					ft_strequ(const char *s1, const char *s2);
int					ft_atoi(const char *s);

#endif
