/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getonechartoken.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:24:13 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/31 13:15:19 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "42-Libft/libft.h"

t_token	*ft_createtoken(char *data, enum e_tokentype type)
{
	t_token	*token;

	token = ft_calloc(sizeof(t_token), 1);
	token->data = data;
	token->type = type;
	return (token);
}

t_token	*ft_gettwochartoken(char *str, int *i, enum e_tokentype type, char chr)
{
	char	schr[3];

	(*i)++;
	if (str[*i] == chr)
	{
		schr[0] = chr;
		schr[1] = chr;
		schr[2] = 0;
		(*i)++;
		return (ft_createtoken(ft_strdup(schr), type));
	}
	return (NULL);
}

t_token	*ft_getonechartoken(enum e_tokentype type, int *i, char chr)
{
	char	schr[2];

	(*i)++;
	schr[0] = chr;
	schr[1] = 0;
	return (ft_createtoken(ft_strdup(schr), type));
}
