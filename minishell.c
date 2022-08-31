/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:19:49 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/31 13:18:59 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include "./42-Libft/libft.h"
#include "minishell.h"
#include <unistd.h>

t_mini	*g_mini;

static void	init_mini(char **env)
{
	g_mini = ft_calloc(sizeof(t_mini), 1);
	g_mini->env = ft_copyarr_str(env);
}

static void	loop(void)
{
	char	*input;

	while (!g_mini->exitflag)
	{
		input = ft_getinput();
		if (!input)
			break ;
		ft_execline(input);
		free(input);
	}
}

int	main(int ac, char **av, char **env)
{
	static int	exit;

	(void)av;
	init_mini(env);
	if (ac == 1)
		loop();
	ft_freearr_str(g_mini->env);
	free(g_mini);
	return (exit);
}
