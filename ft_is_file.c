/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:27:11 by makbulut          #+#    #+#             */
/*   Updated: 2022/09/03 15:29:55 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>

int	ft_is_file(char *path)
{
	struct stat	path_stat;

	stat(path, &path_stat);
	return ((((path_stat.st_mode) & S_IFMT) == S_IFREG));
}
