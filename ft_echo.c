/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:45:40 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/02 20:04:40 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

static int	ft_echo_check(t_command *cmd, int i)
{
	if (cmd->arguments[1][0] != '-')
		return (0);
	while (cmd->arguments[1][i] && cmd->arguments[1][i] == 'n')
		i++;
	if (!cmd->arguments[1][i])
		return (1);
	return (0);
}

int	ft_echo(t_command *command)
{
	int	i;
	int	checkreturn;

	if (!command->arguments[1])
	{
		ft_putstr_fd("\n", command->out);
		return (0);
	}
	checkreturn = ft_echo_check(command, 1);
	if (checkreturn && !command->arguments[2])
		return (0);
	i = 1;
	if (!checkreturn)
		i = 0;
	while (command->arguments[++i])
	{
		ft_putstr_fd(command->arguments[i], command->out);
		if (command->arguments[i + 1])
			ft_putstr_fd(" ", command->out);
	}
	if (command->arguments[1] && !checkreturn)
		ft_putstr_fd("\n", command->out);
	return (0);
}
