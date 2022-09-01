/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:09:29 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/01 17:17:14 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

int	ft_exit(t_command *cmd)
{
	(void)cmd;
	g_mini->exitflag = 1;
	if (!g_mini->issubshell && cmd->in == 0 && cmd->out == 1)
		ft_putendl_fd("exit", 2);
	if (cmd->arguments[1])
	{
		if (ft_isnumeric(cmd->arguments[1]))
			return (ft_atoi(cmd->arguments[1]));
		else
		{
			ft_putstr_fd("bash: exit :", 2);
			ft_putstr_fd(cmd->arguments[1], 2);
			ft_putendl_fd(": numeric argument required", 2);
			return (255);
		}
	}
	return (0);
}
