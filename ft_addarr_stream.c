/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addarr_stream.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:22:30 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/30 14:22:57 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_addarr_stream(t_stream ***arr, t_stream *new)
{
	ft_addarr((void ***)arr, (void *)new);
}
