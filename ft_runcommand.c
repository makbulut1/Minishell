/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_runcommand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:01:35 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/03 16:58:11 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>

static void	check_errors(t_command *cmd, char *path)
{
	if (ft_filexists(path))
	{
		ft_puterrln("is a directory", cmd->command);
		g_mini->return_code = 126;
	}
	else
	{
		g_mini->return_code = 127;
		ft_puterrln("No such file or directory", cmd->command);
	}
}

char	*ft_path_controler(t_command *cmd, char *cmdpath)
{
	if (ft_getenvindex("PATH") != -1)
		return (cmdpath = ft_find_in_path(cmd->command));
	return (NULL);
}

static int	exec_process(t_command *cmd)
{
	char	*cmdpath;
	pid_t	pid;

	cmdpath = NULL;
	if (!cmd->command)
	{
		ft_open_reads(cmd);
		return (-1);
	}
	cmdpath = ft_path_controler(cmd, cmdpath);
	pid = -1;
	if (cmdpath)
	{
		if (ft_is_file(cmdpath))
			pid = ft_init_process(cmd, cmdpath);
		else
			check_errors(cmd, cmdpath);
	}
	else
	{
		ft_puterrln("command not found", cmd->command);
		g_mini->return_code = 127;
	}
	free(cmdpath);
	return (pid);
}

int	ft_runcommand(t_command *cmd)
{
	pid_t	pid;

	ft_pars_quote(cmd);
	if (cmd->subshells)
		pid = ft_initsubshell(cmd);
	else if (ft_isbuiltin(cmd->command))
		pid = ft_initbuiltin(cmd);
	else if (!cmd->command)
		pid = ft_initredirects(cmd);
	else
		pid = exec_process(cmd);
	return (1);
}
