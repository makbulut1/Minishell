/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initredirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:23:36 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/02 20:25:21 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_initredirects(t_command *cmd)
{
	if (ft_open_reads(cmd))
	{
		g_mini->return_code = 0;
		return (-1);
	}
	g_mini->return_code = 1;
	return (0);
}
