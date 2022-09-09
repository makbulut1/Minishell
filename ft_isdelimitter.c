/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdelimitter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:23:22 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/05 13:52:56 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isdelimitter(char chr)
{
	return (ft_isspace(chr) || \
			chr == '<' || \
			chr == '>' || \
			chr == '|' || \
			chr == '(' || \
			chr == ')');
}
