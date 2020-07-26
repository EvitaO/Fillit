/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 20:22:48 by mvan-hou      #+#    #+#                 */
/*   Updated: 2020/07/26 21:58:41 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*a;
	size_t			i;

	a = NULL;
	i = 0;
	if (size > 0)
	{
		a = (unsigned char*)malloc(size);
		if (!a)
			return (NULL);
		while (i < size)
		{
			a[i] = 0;
			i++;
		}
	}
	return (a);
}
