/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pieces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknuutti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:55:20 by jknuutti          #+#    #+#             */
/*   Updated: 2020/02/17 19:58:20 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Allocates memory for the array of pieces. Then counts the
** letter and the coordinates which we have to use for the current
** piece. After that the function allocates memory for the current
** piece and fills in the struct information (coordinates and
** letter). After that we move onto the next piece (tetromino).
** (/ is -1 and . is -2) 
*/

static t_pieces	*maker(char let, char *str)
{
	t_pieces	*piece;

	if (!(piece = (t_pieces*)ft_memalloc(sizeof(t_pieces))))
		return (NULL);
	piece->letter = let;
	piece->y1 = str[0] - '0';
	piece->x1 = str[1] - '0';
	piece->y2 = str[2] - '0';
	piece->x2 = str[3] - '0';
	piece->y3 = str[4] - '0';
	piece->x3 = str[5] - '0';
	return (piece);
}

static t_pieces	*coordinates(int i, char let)
{
	t_pieces	*piece;

	piece = NULL;
	piece = (i == 0) ? maker(let, "102030") : piece;
	piece = (i == 1) ? maker(let, "010203") : piece;
	piece = (i == 2) ? maker(let, "011011") : piece;
	piece = (i == 3) ? maker(let, "010212") : piece;
	piece = (i == 4) ? maker(let, "10202/") : piece;
	piece = (i == 5) ? maker(let, "101112") : piece;
	piece = (i == 6) ? maker(let, "011020") : piece;
	piece = (i == 7) ? maker(let, "101/1.") : piece;
	piece = (i == 8) ? maker(let, "102021") : piece;
	piece = (i == 9) ? maker(let, "010210") : piece;
	piece = (i == 10) ? maker(let, "011121") : piece;
	piece = (i == 11) ? maker(let, "011112") : piece;
	piece = (i == 12) ? maker(let, "101/2/") : piece;
	piece = (i == 13) ? maker(let, "01101/") : piece;
	piece = (i == 14) ? maker(let, "101121") : piece;
	piece = (i == 15) ? maker(let, "010211") : piece;
	piece = (i == 16) ? maker(let, "101120") : piece;
	piece = (i == 17) ? maker(let, "101/20") : piece;
	piece = (i == 18) ? maker(let, "1/1011") : piece;
	return (piece);
}

t_pieces		**make_pieces(int *p_nbrs, int count)
{
	int			i;
	t_pieces	**pieces;
	char		letter;

	i = 0;
	letter = 'A';
	if (!(pieces = (t_pieces**)malloc(sizeof(t_pieces*) * (count + 1))))
		return (NULL);
	while (i < count)
	{
		if (!(pieces[i] = coordinates(p_nbrs[i], letter)))
			return (NULL);
		i++;
		letter++;
	}
	pieces[i] = NULL;
	return (pieces);
}
