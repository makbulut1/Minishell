/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:19:49 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/21 14:14:41 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <readline/readline.h>
#include <readline/history.h>
#include "./42-Libft/libft.h"
#include "minishell.h"
#include <unistd.h>

t_mini	*g_mini;

char	*ft_create_prompt(void)
{
	char	*prompt;
	char	*cwd;
	int		len;

	cwd = "\x1b[31mminishell % \x1b[0m";
	len = ft_strlen(cwd);
	prompt = ft_calloc(sizeof(char), len + 1);
	ft_memmove(prompt,cwd, len);
	return (prompt);
}

char	*ft_getinput(void)
{
	char	*input;
	char	*prompt;

	prompt = ft_create_prompt();
	input = readline(prompt);
	if(input && *input)
		add_history(input);
	free(prompt);
	return(input);
}

void	loop(void)
{
	char	*input;

	while (!g_mini->exit_status)
	{
		input = ft_getinput();
		if (!input)
			break;
		free(input);
	}
	
}

int	ft_arrlen(void **arr)
{
	int	len;

	len = 0;
	while (arr && arr[len])
	{
		len++;
	}
	return (len);
}

char	**ft_copyarr_str(char	**arr)
{
	char	**ret;
	int		i;

	ret = ft_calloc(sizeof(char *), ft_arrlen((void **)arr) + 1);
	i = 0;
	while (arr && *arr)
	{
		ret[i++] = ft_strdup(*arr++);
	}
	return (ret);
}

void	ft_freearr_str(char **arr)
{
	ft_freearr((void **)arr, free);
}

void	init_mini(char **env)
{
	g_mini = malloc(sizeof(t_mini) * 1);
	g_mini->env = ft_copyarr_str(env);
}

int	main(int ac, char **av, char **env)
{
	(void)av;
	int	exit;
	init_mini(env);
	if(ac == 1)
		loop();
	ft_freearr_str(g_mini->env);
	free(g_mini);
	return (exit);
}
