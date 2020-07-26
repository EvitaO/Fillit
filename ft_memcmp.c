/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 15:19:16 by mvan-hou      #+#    #+#                 */
/*   Updated: 2020/07/26 21:58:48 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char*)s1;
	b = (unsigned char*)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1) && a[i] == b[i])
		i++;
	return (a[i] - b[i]);
}
