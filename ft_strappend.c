/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:52:14 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/01 18:53:52 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42-Libft/libft.h"

void	ft_strappend(char **str, char *appendstr)
{
	char	*old;

	if (!appendstr)
		return ;
	old = *str;
	*str = ft_strjoin(*str, appendstr);
	free(old);
}
