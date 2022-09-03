/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_in_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:05:14 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/03 15:40:19 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42-Libft/libft.h"
#include "minishell.h"
#include <stdlib.h>

static char	*join_path(char *path, char *file)
{
	char	*p;
	int		i;


	i = 0;
	p = ft_calloc(sizeof(char), ft_strlen(path) + ft_strlen(file) + 2);
	while (*path)
		p[i++] = *path++;
	if (p[i - 1] != '/')
		p[i++] = '/';
	while (*file)
		p[i++] = *file++;
	return (p);
}

char	*ft_find_in_path(char *file)
{
	char	**paths;
	char	*path;
	int		i;

	if (ft_ispath(file))
		return (ft_strdup(file));
	paths = ft_split(ft_getenv("PATH"), ':');
	i = 0;
	while (paths[i])
	{
		path = join_path(paths[i++], file);
		if (ft_filexists(path))
			break ;
		free(path);
		path = NULL;
	}
	ft_freearr_str(paths);
	return (path);
}
