/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearsignals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:11:24 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/31 17:12:30 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

void	ft_clearsignals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
