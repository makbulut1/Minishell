/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:09:19 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/04 05:44:14 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

int	ft_pwd(t_command *cmd)
{
	char	buffer[4096];

	getcwd(buffer, 4096);
	ft_putendl_fd(buffer, cmd->out);
	return (0);
}
