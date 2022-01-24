/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syxtyn <syxtyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:49:44 by spineda-          #+#    #+#             */
/*   Updated: 2022/01/22 21:49:16 by syxtyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t		i;
	char		*cdest;
	char		*csrc;
	char		*temp;

	cdest = (char *)dest;
	csrc = (char *)src;
	temp = (char *)malloc(size * sizeof(char));
	i = 0;
	if (size != 0)
	{
		while (i < size)
		{
			temp[i] = csrc[i];
			i++;
		}
		i = 0;
		while (i < size)
		{
			cdest[i] = temp[i];
			i++;
		}
	}
	free(temp);
	return (dest);
}