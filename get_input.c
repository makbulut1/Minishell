/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:56:55 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/04 05:09:33 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"
#include <readline/history.h>

char	*ft_create_prompt(void)
{
	char		*prompt;
	char		*cwd;
	int			len;

	cwd = "\x1b[31mminishell % \x1b[0m";
	len = ft_strlen(cwd);
	prompt = ft_calloc(sizeof(char), len + 1);
	ft_memmove(prompt, cwd, len);
	return (prompt);
}

char	*ft_getinput(void)
{
	char	*input;
	char	*prompt;

	prompt = ft_create_prompt();
	input = readline(prompt);
	if (input && *input)
		add_history(input);
	free(prompt);
	return (input);
}
