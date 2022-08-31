/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterrno_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:34:03 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/31 20:54:39 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42-Libft/libft.h"
#include "minishell.h"

void	ft_puterrno_msg(char *msg)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(": ", 2);
	ft_puterrno();
	ft_putendl_fd("", 2);
}
