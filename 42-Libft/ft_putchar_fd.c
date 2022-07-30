/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:01:41 by makbulut          #+#    #+#             */
/*   Updated: 2022/01/16 19:37:31 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include<fcntl.h> 
void	ft_putchar_fd(char c, int fd)
{
	if (!fd)
		return ;
	write(fd, &c, 1);
}

/*
int	main()
{
	int fd = open("txt.txt",O_CREAT | O_RDWR, 0777);
	ft_putchar_fd('B', fd);
}*/
