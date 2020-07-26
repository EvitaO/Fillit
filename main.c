/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 18:41:51 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/26 21:59:04 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	char		*str;
	int			fd;
	t_etris		*tetris;
	int			res;
	char		**board;

	board = NULL;
	if (argc != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	str = read_and_save(fd);
	close(fd);
	res = check_input(str);
	if (res == 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	tetris = make_blocks(str);
	board = make_board();
	solve(tetris, &board, board_size(tetris));
	return (0);
}
