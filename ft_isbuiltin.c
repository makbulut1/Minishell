/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbuiltin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:56:46 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/31 21:03:53 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42-Libft/libft.h"
#include "minishell.h"

int	ft_isbuiltin(char *command)
{
	if (ft_strcmp(BT_ECHO, command) == 0 || \
		ft_strcmp(BT_CD, command) == 0 || \
		ft_strcmp(BT_PWD, command) == 0 || \
		ft_strcmp(BT_EXIT, command) == 0 || \
		ft_strcmp(BT_EXPORT, command) == 0 || \
		ft_strcmp(BT_UNSET, command) == 0 || \
		ft_strcmp(BT_ENV, command) == 0)
		return (1);
	return (0);
}
