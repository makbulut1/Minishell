/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:24:26 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/01 20:27:36 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

int	ft_unset(t_command *command)
{
	int	i;

	i = 0;
	while (command->arguments[++i])
	{
		if (ft_env_check(command->arguments[i]))
			ft_delenv(command->arguments[i]);
		else
		{
			ft_putstr_fd("bash: unset: '", 2);
			ft_putstr_fd(command->arguments[i], 2);
			ft_putendl_fd("':not a valid identifier", 2);
		}
	}
	return (0);
}
