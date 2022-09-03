/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:38:54 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/02 19:45:00 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

int	ft_env(t_command *command)
{
	int	i;

	i = -1;
	while (g_mini->env[++i])
	{
		if (ft_strchr(g_mini->env[i], '='))
			ft_putendl_fd(g_mini->env[i], command->out);
	}
	return (0);
}
