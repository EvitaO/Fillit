/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/09 15:06:53 by mvan-hou      #+#    #+#                 */
/*   Updated: 2020/07/26 21:59:30 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_board(char **board, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < size)
	{
		while (i < size)
		{
			ft_putchar(board[j][i]);
			i++;
		}
		i = 0;
		ft_putchar('\n');
		j++;
	}
}
