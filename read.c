/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 18:41:51 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/26 21:59:37 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*read_and_save(int fd)
{
	int			i;
	char		buf;
	char		*str;
	int			res;

	i = 0;
	str = NULL;
	res = read(fd, &buf, 1);
	if (res < 1)
		return (NULL);
	else
	{
		str = (char*)malloc(sizeof(char*) * (546));
		if (!str)
			return (NULL);
		while (res != '\0')
		{
			str[i] = buf;
			i++;
			res = read(fd, &buf, 1);
		}
		str[i] = '\0';
	}
	return (str);
}
