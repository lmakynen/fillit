/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:26:24 by lmakynen          #+#    #+#             */
/*   Updated: 2020/02/17 19:58:39 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** By using coordinates the solver checks if the piece
** (tetromino) fits into the output. We check if there's
** dots in the places where we are trying to put the letters.
** We also check that we haven't gone outside of the output
** (negative or too large placements). If the piece fits, we
** move onto the next one. If that one doesn't fit, we
** remove the current one and try a different placement
** for it. We move by columns and when we have reached the
** end of the column, we go to the next row (and reset
** the column coordinate). 
*/

static void	insert_piece(t_box *box, t_pieces *piece, int x, int y)
{
	char	let;

	let = piece->letter;
	box->output[y][x] = let;
	box->output[y + piece->y1][x + piece->x1] = let;
	box->output[y + piece->y2][x + piece->x2] = let;
	box->output[y + piece->y3][x + piece->x3] = let;
}

static int	fit_pieces(t_box *box, t_pieces *piece, int x, int y)
{
	if (x + piece->x1 < 0 || x + piece->x1 >= box->size ||
			x + piece->x2 < 0 || x + piece->x2 >= box->size ||
			x + piece->x3 < 0 || x + piece->x3 >= box->size ||
			y + piece->y1 < 0 || y + piece->y1 >= box->size ||
			y + piece->y2 < 0 || y + piece->y2 >= box->size ||
			y + piece->y3 < 0 || y + piece->y3 >= box->size)
		return (0);
	if (box->output[y + piece->y1][x + piece->x1] != '.' ||
			box->output[y + piece->y2][x + piece->x2] != '.' ||
			box->output[y + piece->y3][x + piece->x3] != '.')
		return (0);
	insert_piece(box, piece, x, y);
	return (1);
}

static void	undo_piece(t_box *box, t_pieces *piece, int x, int y)
{
	box->output[y][x] = '.';
	box->output[y + piece->y1][x + piece->x1] = '.';
	box->output[y + piece->y2][x + piece->x2] = '.';
	box->output[y + piece->y3][x + piece->x3] = '.';
}

int			solver(t_box *box, t_pieces **pieces, int piece)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < box->size)
	{
		while (x < box->size)
		{
			while (box->output[y][x] != '.' && x < box->size)
				x++;
			if (fit_pieces(box, pieces[piece], x, y))
			{
				if (!pieces[piece + 1] || solver(box, pieces, piece + 1))
					return (1);
				undo_piece(box, pieces[piece], x, y);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
