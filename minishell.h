/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:39:59 by makbulut          #+#    #+#             */
/*   Updated: 2022/07/27 20:47:14 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
// # include "./../../readline/include/readline/readline.h"
// #  include <readline/rlstdc.h>
# include <readline/history.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2
typedef struct s_mini
{
	char *read;
	char **split;
}	t_mini;

typedef struct	s_sig
{
	int				sigint;
	int				sigquit;
	int				exit_status;
	pid_t			pid;
}				t_sig;

#endif