/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsesubshell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:43:52 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/31 13:25:22 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "./42-Libft/libft.h"

static int	checkreds(t_command *cmd, t_token **tokens, int *start)
{
	if (ft_arrlen((void **)cmd->redirections) > 0)
	{
		ft_syntaxerror(tokens[*start]);
		return (0);
	}
	if (ft_arrlen((void **)cmd->heredocsteps) > 0)
	{
		ft_heredoc(cmd);
		ft_syntaxerror(tokens[*start]);
		return (0);
	}
	return (1);
}

int	ft_parsesubshell(t_command *cmd, t_token **tokens, \
						int *start, int end)
{
	int	i;

	if (!checkreds(cmd, tokens, start))
		return (0);
	i = ft_skipbrackets(tokens, *start, end);
	if (i == -1)
	{
		ft_syntaxerror(tokens[*start]);
		return (0);
	}
	cmd->subshells = ft_parsepipelines(tokens, *start, end);
	if (cmd->command)
		return (0);
	cmd->command = ft_strdup("SUBSHELL");
	cmd->arguments = ft_calloc(sizeof(char *), 1);
	*start = i + 1;
	return (1);
}
