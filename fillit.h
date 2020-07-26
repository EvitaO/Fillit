/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eovertoo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/07 15:51:10 by eovertoo      #+#    #+#                 */
/*   Updated: 2020/07/26 21:58:22 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct			s_etris
{
	char				c;
	int					x[4];
	int					y[4];
	int					width;
	int					height;
	struct s_etris		*next;
}						t_etris;
int						count_blocks(char *str);
int						check_input(char *str);
char					*read_and_save(int fd);
t_etris					*make_blocks(char *str);
char					**make_board(void);
int						board_size(t_etris *block);
void					print_board(char **board, int size);
void					free_board(char **board);
void					free_list(t_etris *list);
void					solve(t_etris *blocks, char ***board, int size);
int						same_blocks(t_etris *block);
char					*ft_strsub(char const *s, unsigned int start,
						size_t len);
void					*ft_memalloc(size_t size);
int						ft_memcmp(const void *s1, const void *s2, size_t n);

#endif
