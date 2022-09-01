/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:44:20 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/01 18:45:58 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

char	*ft_get_key(char *s)
{
	int		len;
	char	*key;

	len = ft_strlenchr(s, '=');
	key = ft_substr(s, 0, len);
	return (key);
}
