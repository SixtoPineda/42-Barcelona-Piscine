/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:10:28 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/21 23:10:35 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	print_error(int error);

int	read_file(char *filename, char **str)
{
	int		fd;
	char	buff[SIZE];
	int		count;
	int		aux_count;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (print_error(1));
	count = 0;
	aux_count = 1;
	while (aux_count)
	{
		aux_count = read(fd, buff, SIZE);
		count += aux_count;
	}
	*str = malloc(sizeof(char) * count);
	if (!*str || close(fd))
		return (print_error(1));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (print_error(1));
	read(fd, *str, count);
	if (close(fd))
		return (print_error(1));
	return (0);
}
