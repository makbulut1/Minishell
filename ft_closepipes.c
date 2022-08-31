/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_closepipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:59:00 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/31 16:51:31 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_closepipes(void)
{
	int	i;

	i = 0;
	while (i < g_mini->pipecount)
		close(g_mini->openedpipes[i++]);
	free(g_mini->openedpipes);
	g_mini->pipecount = 0;
	g_mini->openedpipes = NULL;
}
