/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:36:53 by lmakynen          #+#    #+#             */
/*   Updated: 2020/02/17 19:57:06 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

typedef struct	s_box
{
	int			size;
	char		**output;
}				t_box;

typedef struct	s_pieces
{
	char		letter;
	int			y1;
	int			x1;
	int			y2;
	int			x2;
	int			y3;
	int			x3;
}				t_pieces;

void			errors(int error);
int				solver(t_box *box, t_pieces **pieces, int piece);
char			*peace_maker(char *str);
int				new_lines(char *str);
int				peace_checker(char *str);
int				count_connections(char *str);
t_pieces		**make_pieces(int *p_nbrs, int count);
int				ft_square(int count);
t_box			*ft_make_box(int box_size);
void			free_box(t_box *box);

#endif
