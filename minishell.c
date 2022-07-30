/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:19:49 by makbulut          #+#    #+#             */
/*   Updated: 2022/07/30 21:08:24 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <readline/readline.h>
#include <readline/history.h>
#include "./42-Libft/libft.h"
#include "minishell.h"
#include <unistd.h>

t_sig	g_sig;
void	sig_int(int code)
{
	(void)code;
	if (g_sig.pid == 0)
	{
		ft_putstr_fd("\b\b  ", STDERR);
		ft_putstr_fd("\n", STDERR);
		ft_putstr_fd("promter>>", STDERR);
		g_sig.exit_status = 1;
	}
	else
	{
		ft_putstr_fd("\n", STDERR);
		g_sig.exit_status = 130;
	}
	g_sig.sigint = 1;
}

int	main(void)
{
	t_mini mini;

	signal(SIGINT, &sig_int);
	while (1)
	{
		mini.read = readline("promter>>");
		mini.split = ft_split(mini.read , ' ');
		while(*mini.split)
			ft_putendl_fd(*mini.split++, 1);
	}
	return (0);
}
