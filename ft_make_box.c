/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_box.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknuutti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:49:49 by jknuutti          #+#    #+#             */
/*   Updated: 2020/02/17 19:57:34 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Allocates memory for box (struct) and our output (2D array).
** After that we allocate memory for every row. Then we fill
** in the rows with dots (our empty symbol). There's also a
** function which deletes and frees every output row we have
** made. We need to use this if the output size is too small.
*/

void	free_box(t_box *box)
{
	int		i;

	i = 0;
	while (box->output[i])
	{
		ft_strdel(&(box->output[i]));
		i++;
	}
	free(box->output);
	box->output = NULL;
	free(box);
	box = NULL;
}

t_box	*ft_make_box(int box_size)
{
	t_box	*box;
	int		i;

	if (!(box = (t_box*)malloc(sizeof(t_box))))
		return (NULL);
	if (!(box->output = (char**)malloc(sizeof(char*) * (box_size + 1))))
		return (NULL);
	box->output[box_size] = NULL;
	i = 0;
	while (i < box_size)
	{
		if (!(box->output[i] = (char*)ft_strnew(box_size)))
			return (NULL);
		ft_memset(box->output[i], '.', box_size);
		i++;
	}
	box->size = box_size;
	return (box);
}
