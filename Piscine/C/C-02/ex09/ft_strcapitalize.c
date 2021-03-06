/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spineda- <spineda-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:47:08 by spineda-          #+#    #+#             */
/*   Updated: 2021/12/17 20:38:39 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*ft_strcapitalize(char *src);

void	ft_putstr(char *str)
{
	int l;

	l = 0;
	while (str[l])
	{
		l++;
	}
	write(1, str, l);
}

int		main()
{
	char c[] = "salut, coMMent tu vAs ? 42mOts quArAnTe-dEux; cinQuante+et+un";
	ft_putstr("Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un:");
	ft_putstr(ft_strcapitalize(c));
	ft_putstr(":");
	ft_putstr(c);
}
char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i - 1] < '0') || ((str[i - 1] > '9')
				&& (str[i - 1] < 'A')) || ((str[i - 1] > 'Z')
				&& (str[i - 1] < 'a')) || (str[i - 1] > 'z'))
		{
			if ((str[i] >= 'a') && (str[i] <= 'z'))
				str[i] = str[i] - 32;
		}
		else if (((str[i] >= 'A') && (str[i] <= 'Z')))
				str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
