/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterrno.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:37:51 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/31 20:51:31 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42-Libft/libft.h"
#include "minishell.h"
#include <errno.h>
#include <string.h>

void	ft_puterrno(void)
{
	char	*msg;

	msg = strerror(errno);
	ft_putstr_fd(msg, 2);
}
