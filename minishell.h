/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:39:59 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/21 14:03:56 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_mini
{
	char			*read;
	char			**split;
	int				sigint;
	int				sigquit;
	int				exit_status;
	pid_t			pid;
	char			**env
}	t_mini;

typedef struct	s_sig
{
	;
}				t_sig;

#endif