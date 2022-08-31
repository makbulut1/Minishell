/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:00:00 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/31 13:02:45 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void	ft_addarr_token(t_token ***arr, t_token *new)
{
	ft_addarr((void ***)arr, (void *)new);
}

t_token	**ft_tokens(char *str)
{
	t_token	**tokens;
	t_token	*token;

	tokens = 0;
	while (1)
	{
		token = ft_getnexttoken(str);
		if (!token)
			break ;
		ft_addarr_token(&tokens, token);
	}
	return (tokens);
}

void	ft_execline(char *input)
{
	t_token		**tokens;
	t_pipeline	**pipelines;

	tokens = ft_tokens(input);
	pipelines = NULL;
	if (tokens)
	{
		pipelines = ft_parsepipelines(tokens, 0, ft_arrlen((void **)tokens));
		if (pipelines)
		{
			ft_runpipelines(pipelines);
		}
	}
}
