/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettoken.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:21:31 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/31 13:07:07 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

static t_token	*onechartoken(char *str, int *i)
{
	if (str[*i] == '|')
		return (ft_getonechartoken(PIPE, i, '|'));
	if (str[*i] == '>')
		return (ft_getonechartoken(RED_CREATE, i, '>'));
	if (str[*i] == '<')
		return (ft_getonechartoken(RED_INPUT, i, '<'));
	return (NULL);
}

static t_token	*twochartoken(char *str, int *i)
{
	if (str[*i] == '>' && str[*i + 1] == '>')
		return (ft_gettwochartoken(str, i, RED_APPEND, '>'));
	if (str[*i] == '<' && str[*i + 1] == '<')
		return (ft_gettwochartoken(str, i, HEREDOC, '<'));
	return (NULL);
}

t_token	*ft_getnexttoken(char *str)
{
	static int	i;
	t_token		*token;

	token = 0;
	while (str[i])
	{
		token = twochartoken(str, &i);
		if (token)
			break ;
		token = onechartoken(str, &i);
		if (token)
			break ;
		if (!ft_isdelimitter(str[i]))
			return (ft_getwordtoken(str, &i));
		else
			i++;
	}
	if (token)
		return (token);
	i = 0;
	return (NULL);
}
