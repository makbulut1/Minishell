/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initsubshell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:08:55 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/04 05:57:06 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

static void	helper(t_command *cmd)
{
	if (ft_arrlen((void **)cmd->redirections) > 0)
	{
		ft_connectio(cmd);
		ft_closepipes();
		ft_runpipelines(cmd->subshells);
	}
	else
	{
		ft_runpipelines(cmd->subshells);
		ft_closepipes();
	}
}

int	ft_initsubshell(t_command *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		g_mini->issubshell = 1;
		ft_clearsignals();
		if (!ft_open_reds(cmd))
		{
			g_mini->exitflag = 1;
			return (-1);
		}
		helper(cmd);
		g_mini->exitflag = 1;
		return (-1);
	}
	return (pid);
}
