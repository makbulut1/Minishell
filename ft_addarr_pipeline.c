/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addarr_pipeline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 22:10:59 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/31 13:26:16 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_addarr_pipeline(t_pipeline ***arr, t_pipeline *new)
{
	ft_addarr((void ***)arr, (void *)new);
}
