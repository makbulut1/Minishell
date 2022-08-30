/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:00:40 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/30 14:30:49 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <readline/readline.h>

static void heredoc_signalhandler(int sig)
{
    (void)sig;
    exit (1);
}

static int	ft_strcmp(char *str1, char *str2)
{
	if (str1 && str2)
	{
		while (*str1 && *str2 && *str1 == *str2)
		{
			str1++;
			str2++;
		}
		return (*str1 - *str2);
	}
	return (1);
}

static void heredocread(char *finish, int fd)
{
    char    *line;

    while (1)
    {
        line = readline("> ");
        if (ft_strcmp(line, finish) == 0 || !line)
        {
            free(line);
            break ;
        }
        write(fd, line, ft_strlen(line));
        write(fd, "\n", 1);
        free(line);
    }
}

static int  takeheredoc(t_command *cmd, char *finish)
{
    int     retcode;
    int     p[2];
    pid_t   pid;

    pipe(p);
    pid = fork();
    if (pid == 0)
    {
        signal(SIGINT, heredoc_signalhandler);
        close(p[0]);
        heredocread(finish, p[1]);
        close(p[1]);
        exit(1);
    }
    close(p[1]);
    waitpid(pid, &retcode, 0);
    if ((((retcode) & 0xff00) >> 8) != 0)
    {
        close(p[0]);
        return (0);
    }
    if (cmd->in != 0)
        close(cmd->in);
    cmd->in = p[0];
    return (1);
}

int ft_heredoc(t_command *cmd)
{
    int i;

    i = 0;
    while (cmd->heredocsteps && cmd->heredocsteps[i])
    {
        if (!takeheredoc(cmd, cmd->heredocsteps[i++]))
            return (1);
    }
    return (0);
}