/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumaric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:14:27 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/01 17:17:49 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42-Libft/libft.h"

int	ft_isnumeric(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}
