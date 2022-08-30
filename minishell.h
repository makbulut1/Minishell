/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:39:59 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/30 18:28:48 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define FT_DEFINES_H
# define DEP_AND 1
# define DEP_OR 2
# define STREAM_IN 1
# define STREAM_OUT 2

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

enum e_starmods {
	LEFT_STAR,
	RIGHT_STAR,
	DB_STARS
};

typedef struct s_token {
	char				*data;
	enum e_tokentype	type;
}	t_token;

typedef struct s_stream {
	char	*path;
	int		type;
	int		appendmode;
}	t_stream;

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

typedef struct s_mini {
	int		return_code;
	int		exitflag;
	int		intflag;
	int		pipecount;
	int		issubshell;
	int		*openedpipes;
	char	**env;
}					t_mini;

extern t_mini		*g_mini;

char		**ft_copyarr_str(char	**arr);
void		ft_freearr_str(char **arr);
void		ft_freearr(void **arr, void (*f)(void *));
char		*ft_create_prompt(void);
char		*ft_getinput(void);
void		ft_execline(char *input);
t_pipeline	**ft_parsepipelines(t_token **tokens, int start, int end);
t_token		*ft_getnexttoken(char *str);
t_token		*ft_getonechartoken(enum e_tokentype type, int *i, char chr);
t_token		*ft_gettwochartoken(char *str, int *i, enum e_tokentype type, \
																char chr);
int			ft_isdelimitter(char chr);
t_token		*ft_getwordtoken(char *str, int *i);
int			ft_isquate(char chr);
void		ft_addarr(void ***arr, void *new);
int			ft_arrlen(void **arr);
t_token		*ft_createtoken(char *data, enum e_tokentype type);
int			ft_isspace(char chr);
void		ft_syntaxerror(t_token *token);
void		ft_freearr_pipeline(t_pipeline **pipes);
void		ft_freepipeline(t_pipeline *p);
int			ft_islogic(t_token *tok);
int			ft_skipbrackets(t_token **tokens, int start, int end);
void		ft_freearr_command(t_command **cmd);
void		ft_freecommand(t_command *command);
void		ft_addarr_pipeline(t_pipeline ***arr, t_pipeline *new);
void		ft_addarr_command(t_command ***arr, t_command *new);
t_command	**ft_parsecommands(t_token **tokens, int start, int end);
void		ft_freestream(t_stream *stream);
t_command	*ft_parsecommand(t_token **tokens, int start, int end);
int 		ft_parsesubshell(t_command *cmd, t_token **tokens, \
						int *start, int end);
int			ft_parsewordtoken(t_command *cmd, t_token **tokens, int i);
void	    ft_addarr_str(char ***arr, char *new);
int			ft_parseheredoc(t_command *cmd, t_token **tokens, int *i);
int			ft_heredoc(t_command *cmd);
int			ft_parseredoutput(t_command *cmd, t_token **tokens, int *i);
int			ft_parseredinput(t_command *cmd, t_token **tokens, int *i);
void		ft_addarr_stream(t_stream ***arr, t_stream *new);

#endif