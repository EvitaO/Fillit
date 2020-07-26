/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   board.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/26 21:57:44 by anonymous     #+#    #+#                 */
/*   Updated: 2020/07/26 21:57:47 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			same_blocks(t_etris *block)
{
	t_etris	*search;

	search = block;
	while (search->next)
	{
		if (ft_memcmp(block->x, block->next->x, sizeof(block->x)) == 0 &&
		ft_memcmp(block->y, block->next->y, sizeof(block->y)) == 0)
			search = search->next;
		else
			return (0);
	}
	return (1);
}

char		*make_line(void)
{
	int		i;
	char	*line;

	i = 0;
	line = (char*)ft_memalloc(sizeof(char) * (16 + 2));
	while (i < 16)
	{
		line[i] = '.';
		i++;
	}
	line[i] = '\n';
	return (line);
}

int			sqrt_block(int nbr)
{
	int				i;

	i = 2;
	while (i * i < nbr)
		i++;
	return (i);
}

int			board_size(t_etris *block)
{
	int				i;
	int				max;
	t_etris			*tmp;

	i = 0;
	max = 0;
	if (!block)
		return (0);
	tmp = block;
	while (tmp)
	{
		if (i < 3)
		{
			if (tmp->width > max)
				max = tmp->width;
			if (tmp->height > max)
				max = tmp->height;
		}
		tmp = tmp->next;
		i++;
	}
	if (max + 1 > sqrt_block(i * 4))
		return (max + 1);
	return (sqrt_block(i * 4));
}

char		**make_board(void)
{
	int		x;
	char	**board;

	board = (char**)ft_memalloc(sizeof(char*) * 16);
	if (!board)
		return (NULL);
	x = 0;
	while (x < 16)
	{
		board[x] = make_line();
		if (!*board[x])
		{
			free_board(board);
			return (NULL);
		}
		x++;
	}
	return (board);
}
