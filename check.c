/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 18:41:51 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/26 21:58:06 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_format(char *str)
{
	int dot;
	int block;
	int nl;

	dot = 0;
	block = 0;
	nl = 0;
	while (*str != '\0' && (*str == '.' || *str == '\n' || *str == '#'))
	{
		if (*str == '#')
			block++;
		if (*str == '.')
			dot++;
		if (*str == '\n' && ((dot + block) % 4 == 0 || nl % 4 == 0))
			nl++;
		if (*str == '\n' && nl % 5 == 0 && (dot + block) % 16 != 0)
			return (0);
		str++;
	}
	if ((block % 4 != 0 || (dot + block) % 4 != 0 || nl % 5 != 4) ||
			(block / 4) * 12 != dot)
		return (0);
	return (1);
}

int			check_blocks(char *str, int j)
{
	int links;
	int i;

	i = 0;
	links = 0;
	while (str[i + j] != '\0' && i < 21)
	{
		if (str[i + j] == '#')
		{
			if (i + j > 0 && str[i - 1 + j] == '#')
				links++;
			if (i >= 5 && str[i - 5 + j] == '#')
				links++;
			if (str[i + 1 + j] == '#')
				links++;
			if (i <= 13 && str[i + 5 + j] == '#')
				links++;
		}
		i++;
	}
	if (links == 6 || links == 8)
		return (1);
	return (0);
}

int			count_blocks(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '#')
			count++;
		i++;
	}
	if (i > 545)
		return (0);
	return (count / 4);
}

int			check_input(char *str)
{
	int count;
	int	add;

	add = 0;
	if (str == NULL)
		return (0);
	if (check_format(str) == 0)
		return (0);
	count = count_blocks(str);
	if (count <= 0)
		return (0);
	while (count > 0)
	{
		if (check_blocks(str, add) == 0)
			return (0);
		count--;
		add += 21;
	}
	return (1);
}
