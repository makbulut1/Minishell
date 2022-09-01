/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:44:15 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/01 19:02:53 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

static void	set_reset(char *s)
{
	char	*key;
	char	*value;

	if (!ft_strchr(s, '='))
	{
		ft_setenv(s, 0);
		return ;
	}
	value = ft_get_value(s);
	key = ft_get_key(s);
	if (!value)
	{
		ft_setenv(key, "");
		return ;
	}
	ft_setenv(key, value);
}

int	ft_export(t_command *cmd)
{
	int	i;

	i = 0;
	if (!cmd->arguments[1])
		ft_onlyexport(cmd);
	else
	{
		while (cmd->arguments[++i])
		{
			if (ft_env_check(cmd->arguments[i]))
				set_reset(cmd->arguments[i]);
			else
			{
				ft_putstr_fd("bash: export: '", 2);
				ft_putstr_fd(cmd->arguments[i], 2);
				ft_putendl_fd("':not a valid identifier", 2);
				return (1);
			}
		}
	}
	return (0);
}
