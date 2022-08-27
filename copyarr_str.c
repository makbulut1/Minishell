/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyarr_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:58:20 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/27 12:59:18 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "42-Libft/libft.h"

int	ft_arrlen(void **arr)
{
	int	len;

	len = 0;
	while (arr && arr[len])
		len++;
	return (len);
}

char	**ft_copyarr_str(char	**arr)
{
	char	**ret;
	int		i;

	ret = ft_calloc(sizeof(char *), ft_arrlen((void **)arr) + 1);
	i = 0;
	while (arr && *arr)
		ret[i++] = ft_strdup(*arr++);
	return (ret);
}
