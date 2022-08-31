/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearr_pippeline.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:10:26 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/31 13:05:13 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void	ft_freepipeline(t_pipeline *p)
{
	if (p)
		ft_freearr_command(p->commands);
	free(p);
}

void	ft_freearr_pipeline(t_pipeline **pipes)
{
	ft_freearr((void **)pipes, (void (*)(void *))ft_freepipeline);
}
