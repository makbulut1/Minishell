/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freecommand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:56:39 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/27 23:57:00 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_freecommand(t_command *cmd)
{
	if (cmd)
	{
		if (cmd->out != 1)
			close(cmd->out);
		if (cmd->in != 0)
			close(cmd->in);
		ft_freearr_str(cmd->arguments);
		ft_freearr_str(cmd->heredocsteps);
		ft_freearr((void **)cmd->redirections, (void (*)(void *))ft_freestream);
		ft_freearr_pipeline(cmd->subshells);
		free(cmd->command);
		free(cmd);
	}
}
