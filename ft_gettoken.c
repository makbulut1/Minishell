/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettoken.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:21:31 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/21 19:29:54 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token *ft_getnexttoken(char *str)
{
    static int  i;
    t_token     *token;

    token = NULL;
    while (str[i])
    {
        token = twochartoken(str, &i);
    }
    if (token)
        return (token);
    i = 0;
    return (NULL);
}
