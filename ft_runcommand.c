/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_runcommand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:01:35 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/03 13:06:42 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

int	ft_runcommand(t_command *cmd)
{
	pid_t	pid;

	// ft_parsewildcard(cmd, 0, 0);
	ft_pars_quote(cmd);
	if (cmd->subshells)
		pid = ft_initsubshell(cmd);
	else if (ft_isbuiltin(cmd->command))
		pid = ft_initbuiltin(cmd);
	else if (!cmd->command)
		pid = ft_initredirects(cmd);
	return (1);
}
