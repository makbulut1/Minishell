/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntaxerror.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:12:18 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/31 13:26:42 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

void	ft_syntaxerror(t_token *token)
{
	if (token)
	{
		ft_putstr_fd("bash: sytax error near unexpected token `", 2);
		ft_putstr_fd(token->data, 2);
		ft_putstr_fd("'\n", 2);
	}
	else
		ft_putstr_fd("bash: sytax error near unexpected token `newline'", 2);
	g_mini->return_code = 258;
}
