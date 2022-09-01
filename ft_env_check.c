/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:05:14 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/01 19:08:13 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env_check(char *s)
{
	int	i;

	i = 0;
	if (!ft_isalpha_underscore(s[i++]))
		return (0);
	while (s[i] && s[i] != '=')
	{
		if (!ft_is_env(s[i++]))
			return (0);
	}
	return (1);
}
