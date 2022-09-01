/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:28:29 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/01 20:36:56 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42-Libft/libft.h"
#include "minishell.h"

void	ft_delenv(char *name)
{
	int		i;
	int		j;
	int		index_of_variable;
	int		len_of_env;
	char	**new_env;

	index_of_variable = ft_getenvindex(name);
	if (index_of_variable == -1)
		return ;
	len_of_env = ft_arrlen((void **)g_mini->env);
	new_env = ft_calloc(sizeof(char *), len_of_env);
	i = -1;
	j = 0;
	while (g_mini->env[++i])
	{
		if (i == index_of_variable)
			j++;
		new_env[i] = g_mini->env[i + j];
	}
	free(g_mini->env[index_of_variable]);
	free(g_mini->env);
	g_mini->env = new_env;
}
