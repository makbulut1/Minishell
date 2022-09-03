/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:09:19 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/02 20:12:41 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

int	ft_pwd(t_command *cmd)
{
	char	buffer[4096];

	getcwd(buffer, 4096);
	ft_putstr_fd(buffer, cmd->out);
	return (0);
}
