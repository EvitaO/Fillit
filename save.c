/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 18:41:51 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/26 21:59:45 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		format_blocks(t_etris *block, int xmin, int ymin)
{
	int i;
	int width;
	int height;

	i = 0;
	width = 0;
	height = 0;
	while (i < 4)
	{
		block->x[i] = block->x[i] - xmin;
		block->y[i] = block->y[i] - ymin;
		if (block->x[i] >= width)
			width = block->x[i];
		if (block->y[i] >= height)
			height = block->y[i];
		i++;
	}
	block->width = width;
	block->height = height;
}

void		set_in_block(t_etris *block, char *str)
{
	int				i;
	int				j;
	int				xmin;
	int				ymin;

	i = 0;
	j = 0;
	xmin = 10;
	ymin = 10;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			block->x[j] = i % 5;
			block->y[j] = i / 5;
			if (i % 5 < xmin)
				xmin = i % 5;
			if (i / 5 < ymin)
				ymin = i / 5;
			j++;
		}
		i++;
	}
	free(str);
	format_blocks(block, xmin, ymin);
}

t_etris		*fill_block(t_etris *block)
{
	char		c;
	t_etris		*start;

	c = 'A';
	start = block;
	if (!block)
		return (NULL);
	while (block)
	{
		block->c = c;
		c++;
		block = block->next;
	}
	return (start);
}

t_etris		*make_list(char *str, int cnt, int strstart)
{
	t_etris			*start;
	t_etris			*block;

	start = (t_etris*)ft_memalloc(sizeof(t_etris));
	if (!start)
		return (NULL);
	block = start;
	while (cnt > 0)
	{
		cnt--;
		set_in_block(block, ft_strsub(str, strstart, 20));
		if (cnt == 0)
			break ;
		block->next = (t_etris*)ft_memalloc(sizeof(t_etris));
		if (!block->next)
		{
			free_list(start);
			return (NULL);
		}
		block = block->next;
		strstart += 21;
	}
	block->next = NULL;
	return (start);
}

t_etris		*make_blocks(char *str)
{
	int				cnt;
	int				strstart;
	t_etris			*block;

	strstart = 0;
	cnt = count_blocks(str);
	block = make_list(str, cnt, strstart);
	if (!block)
		return (NULL);
	free(str);
	return (fill_block(block));
}
