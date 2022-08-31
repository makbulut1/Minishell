/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestream.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 22:51:53 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/31 13:05:42 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

void	ft_freestream(t_stream *stream)
{
	if (stream)
	{
		free(stream->path);
		free(stream);
	}
}
