/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:22:51 by eros-gir          #+#    #+#             */
/*   Updated: 2021/12/05 17:14:26 by spineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

char	esquinas(int x, int y, int j, int i)
{
	char	s;

	s = ' ';
	if (i == 0 && j == 0)
	{
		s = '/';
	}
	else if (i == 0 && j == x -1)
	{
		s = '\\';
	}
	else if (i == y -1 && j == 0)
	{
		s = '\\';
	}
	else if (i == y -1 && j == x -1)
	{
		s = '/';
	}
	return (s);
}

char	lineas(int x, int y, int j, int i)
{	
	char	s;

	if ((j == 0 && (i > 0 && i < y -1))
		|| (j == x -1 && (i > 0 && i < y -1)))
	{
		s = '*';
	}
	else if ((i == 0 && (j > 0 && j < x -1))
		|| (i == y -1 && (j > 0 && j < x -1)))
	{
		s = '*';
	}
	else
	{
		s = esquinas(x, y, j, i);
	}
	return (s);
}

int	infogood(int x, int y)
{
	if (x < 1 || y < 1)
	{	
		write(1, "Error: 'x' and 'y' must be positive numbers.\n", 46);
		return (0);
	}
	else
	{
		return (1);
	}
}

void	rush01(int x, int y)
{
	int		i;
	int		j;
	char	s;
	int		f;

	s = '-';
	i = 0;
	f = infogood(x, y);
	while (i < y && f == 1)
	{
		j = 0;
		while (j < x)
		{
			s = lineas(x, y, j, i);
			j++;
			ft_putchar(s);
		}
		i++;
		ft_putchar('\n');
	}
}
