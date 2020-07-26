/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 13:05:42 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/26 21:58:31 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_board(char **board)
{
	int i;

	i = 0;
	while (i < 16)
	{
		free(board[i]);
		i++;
	}
	free(board);
}

void		free_list(t_etris *list)
{
	t_etris		*tmp;

	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}
