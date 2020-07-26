/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:19:05 by mvan-hou      #+#    #+#                 */
/*   Updated: 2020/07/26 21:59:54 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_pos(t_etris *block, char **board, int x, int y)
{
	if (board[block->y[0] + y][block->x[0] + x] == '.' &&
	board[block->y[1] + y][block->x[1] + x] == '.' &&
	board[block->y[2] + y][block->x[2] + x] == '.' &&
	board[block->y[3] + y][block->x[3] + x] == '.')
		return (1);
	return (0);
}

void		place_block(t_etris *block, char **board, int x, int y)
{
	board[block->y[0] + y][block->x[0] + x] = block->c;
	board[block->y[1] + y][block->x[1] + x] = block->c;
	board[block->y[2] + y][block->x[2] + x] = block->c;
	board[block->y[3] + y][block->x[3] + x] = block->c;
}

void		remove_block(t_etris *block, char **board, int x, int y)
{
	board[block->y[0] + y][block->x[0] + x] = '.';
	board[block->y[1] + y][block->x[1] + x] = '.';
	board[block->y[2] + y][block->x[2] + x] = '.';
	board[block->y[3] + y][block->x[3] + x] = '.';
}

int			fill(t_etris *block, char **board, int size)
{
	int x;
	int y;

	y = 0;
	while (y + block->height < size)
	{
		x = 0;
		while (x + block->width < size)
		{
			if (check_pos(block, board, x, y) == 1)
			{
				place_block(block, board, x, y);
				if (block->next == NULL || fill(block->next, board, size) == 1)
					return (1);
				remove_block(block, board, x, y);
				if (block->c == 'A' && same_blocks(block) == 1)
					return (0);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void		solve(t_etris *blocks, char ***board, int size)
{
	int s;

	if (size == 0 || *board == NULL)
		return ;
	s = size;
	if (fill(blocks, *board, s) == 1)
	{
		print_board(*board, s);
		free_board(*board);
		free_list(blocks);
		return ;
	}
	else
	{
		s++;
		solve(blocks, board, s);
	}
}
