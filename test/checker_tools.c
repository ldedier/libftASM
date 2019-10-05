/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:33:39 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/03 18:33:39 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftasm_checker.h"

char *ft_strnew(size_t size)
{
	char *str;

	str = malloc(size + 1);
	bzero(str, size + 1);
	return (str);
}

void	ft_compare_strings(char *mine, char *original)
{
	dprintf(2, "mine: %s, wanted: %s\n", mine, original);
}

void	ft_compare_integers(int mine, int original)
{
	dprintf(2, "mine: %d, wanted: %d\n", mine, original);
}

int		process_test(int index)
{
	int		ret;
	pid_t	pid_test;
	pid_t	pid_timeout;
	int		pid_received;

	if (!(pid_test = fork()))
	{
		ret = g_funcs[index].func();
		exit(ret);
	}
	if (!(pid_timeout = fork()))
	{
		sleep(TIMEOUT_LIMIT);
		exit(2);
	}
	while ((pid_received = wait(&ret)))
	{
		if (pid_received == pid_timeout)
			kill(pid_test, SIGTERM);
		else if (pid_received == pid_timeout)
			kill(pid_timeout, SIGTERM);
//		wait(NULL);
		return (ret);
	}
	exit(1);
}

void	print_signal(int signal)
{
	printf("%s (", RED);
	if (signal == 11)
		printf("SIGSEGV");
	else if (signal == 2)
		printf("SIGINT");
	else if (signal == 10)
		printf("SIGBUS");
	else if (signal == 6)
		printf("SIGABRT");
	else if (signal == 6)
		printf("SIGKILL");
	printf(")%s", EOC);
}

int		process_exit_status(int status, int *success)
{
	int	exit_status;
	int signal;

	if ((exit_status = WEXITSTATUS(status))
			|| (WIFSIGNALED(status) && (signal = WTERMSIG(status))))
	{
		printf("%sKO%s", RED, EOC);
		if (exit_status == 2)
			printf("%s (timeout)%s", RED, EOC);
		else if (WIFSIGNALED(status))
			print_signal(signal);
		return (1);
	}
	else
	{
		printf("%sOK √%s", GREEN, EOC);
		(*success)++;
		return (0);
	}
}
