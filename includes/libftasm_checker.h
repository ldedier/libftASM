/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftasm_checker.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 23:47:30 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/03 23:47:30 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTASM_CHECKER_H
# define LIBFTASM_CHECKER_H

# include "libftasm.h"
# include <ctype.h>
# include <stdio.h>
# include <limits.h>
# include <signal.h>

# define NB_FUNCTIONS	21
# define TIMEOUT_LIMIT	5


# define TEST_STR		"This is a test string hehehehe I like to hardcode"
# define TEST_STR_NL	TEST_STR "\n"

# define RED        "\x1B[31m"
# define GREEN      "\x1B[32m"
# define YELLOW     "\x1B[33m"
# define BLUE       "\x1B[34m"
# define MAGENTA    "\x1B[35m"
# define CYAN       "\x1B[36m"
# define WHITE      "\x1B[37m"
# define L_GREY     "\x1B[90m"
# define L_BLUE     "\x1B[94m"
# define L_MAGENTA  "\x1B[95m"
# define L_CYAN     "\x1B[96m"
# define L_GREEN    "\e[1;32m"
# define BRED       "\x1B[41m"
# define BGREEN     "\x1B[42m"
# define BYELLOW    "\x1B[43m"
# define BBLUE      "\x1B[44m"
# define BMAGENTA   "\x1B[44m"
# define BCYAN      "\x1B[46m"
# define BWHITE     "\x1B[47m"
# define BL_BLUE    "\x1B[104m"
# define BL_MAGENTA "\x1B[105m"
# define BL_CYAN    "\x1B[106m"

# define BOLD       "\x1b[1m"
# define UNDERLINE  "\x1b[4m"
# define EOC        "\033[0m"

typedef struct		s_test_func
{
	char			*name;
	int				(*func)(void);
}					t_test_func;

extern int			g_verbose;
extern t_test_func	g_funcs[NB_FUNCTIONS];

int		ft_bzero_tester(void);
int		ft_strcat_tester(void);
int		ft_isalpha_tester(void);
int		ft_isdigit_tester(void);
int		ft_isalnum_tester(void);
int		ft_isascii_tester(void);
int		ft_isprint_tester(void);
int		ft_toupper_tester(void);
int		ft_tolower_tester(void);
int		ft_puts_tester(void);

int		ft_strlen_tester(void);
int		ft_memset_tester(void);
int		ft_memcpy_tester(void);
int		ft_strdup_tester(void);
int		ft_putchar_tester(void);

int		ft_cat_tester(void);

int		ft_strcpy_tester(void);
int		ft_putstr_fd_tester(void);
int		ft_strequ_tester(void);
int		ft_strcmp_tester(void);
int		ft_atoi_tester(void);

void    ft_compare_integers(int mine, int original);
int     process_exit_status(int status, int *success);
int     process_test(int index);
char	*ft_strnew(size_t size);
void	ft_compare_strings(char *mine, char *original);
char	*ft_itoa(int c);
#endif
