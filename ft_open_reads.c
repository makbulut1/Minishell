/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_reads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:08:48 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/03 19:23:52 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"
#include <fcntl.h>

static int	getflags(t_stream *stream)
{
	int	flags;

	flags = O_CREAT | O_WRONLY;
	if (stream->appendmode)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	return (flags);
}

static int	redirectout(t_command *cmd, t_stream *stream)
{
	if (cmd->out != 1 && !g_mini->issubshell)
		close(cmd->out);
	cmd->out = open(stream->path, getflags(stream), 0666);
	if (cmd->out == -1)
	{
		ft_puterrno_msg(stream->path);
		return (0);
	}
	return (1);
}

static int	redirectin(t_command *cmd, t_stream *stream)
{
	if (cmd->out != 1 && !g_mini->issubshell)
		close(cmd->in);
	cmd->in = open(stream->path, O_RDONLY);
	if (cmd->in == -1)
	{
		ft_puterrno_msg(stream->path);
		return (0);
	}
	return (1);
}

int	ft_open_reads(t_command *cmd)
{
	int	i;

	i = 0;
	while (cmd->redirections && cmd->redirections[i])
	{
		if (cmd->redirections[i]->type == STREAM_OUT)
		{
			if (!redirectout(cmd, cmd->redirections[i]))
				return (0);
		}
		else if (cmd->redirections[i]->type == STREAM_IN)
			if (!redirectin(cmd, cmd->redirections[i]))
				return (0);
		i++;
	}
	return (1);
}
