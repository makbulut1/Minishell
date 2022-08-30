/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseredinput.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:18:37 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/30 14:22:10 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

int	ft_parseredinput(t_command *cmd, t_token **tokens, int *i)
{
    t_stream    *stream;

    (*i)++;
    if (tokens[*i] && tokens[*i]->type == WORD)
    {
        stream = ft_calloc(sizeof(t_stream), 1);
        stream->type = STREAM_IN;
        stream->path = ft_strdup(tokens[*i]->data);
        ft_addarr_stream(&(cmd->redirections), stream);
        return (1);
    }
    ft_syntaxerror(tokens[*i]);
    return (0);
}