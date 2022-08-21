/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:39:59 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/21 19:16:56 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

void    ft_freearr(void **arr, void (*f)(void *));

typedef struct s_mini
{
	char			*read;
	char			**split;
	int				sigint;
	int				sigquit;
	int				exit_status;
	pid_t			pid;
	char			**env;
}	t_mini;

enum e_tokentype {
	WORD,
	PIPE,
	RED_APPEND,
	RED_CREATE,
	AND,
	OR,
	RED_INPUT,
	HEREDOC,
	LPAR,
	RPAR
};

typedef struct s_token {
	char				*data;
	enum e_tokentype	type;
}	t_token;

struct				s_pipeline;
typedef struct s_command {
	char				*command;
	char				**heredocsteps;
	char				**arguments;
	t_stream			**redirections;
	int					out;
	int					in;
	struct s_pipeline	**subshells;
}	t_command;

typedef struct s_pipeline {
	t_command	**commands;
	int			dependon;
}	t_pipeline;

typedef struct s_stream {
	char	*path;
	int		type;
	int		appendmode;
}	t_stream;

#endif