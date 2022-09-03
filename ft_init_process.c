/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:30:30 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/03 15:34:13 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

int	ft_init_process(t_command *cmd, char *cmdpath)
{
	pid_t	pid;
	int		exec_return;

	pid = fork();
	if (pid == 0)
	{
		ft_clearsignals();
		if (!ft_open_reads(cmd))
		{
			g_mini->exitflag = 1;
			return (-1);
		}
		ft_connectio(cmd);
		ft_closepipes();
		exec_return = execve(cmdpath, cmd->arguments, g_mini->env);
		if (exec_return != 0)
		{
			ft_puterrno_msg(cmd->command);
			g_mini->exitflag = 1;
			return (-1);
		}
	}
	return (pid);
}
