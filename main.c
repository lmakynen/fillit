/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknuutti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 19:22:19 by jknuutti          #+#    #+#             */
/*   Updated: 2020/02/17 19:58:08 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		errors(int error)
{
	if (error == 1)
	{
		ft_putendl_fd("error", 2);
		exit(0);
	}
	if (error == 2)
	{
		ft_putendl_fd("error with malloc", 2);
		exit(0);
	}
}

static int	input_is_ok(int *piece_types, int count)
{
	int			i;
	int			box_size;
	t_pieces	**pieces;
	t_box		*box;

	if (!(pieces = make_pieces(piece_types, count)))
		errors(2);
	box_size = ft_square(count);
	if (!(box = ft_make_box(box_size)))
		errors(2);
	i = 0;
	while (!solver(box, pieces, 0))
	{
		free_box(box);
		i++;
		if (!(box = ft_make_box(box_size + i)))
			errors(2);
	}
	i = 0;
	while (box->output[i])
	{
		ft_putendl(box->output[i]);
		i++;
	}
	return (0);
}

static int	validate_file(char *content)
{
	int		i;
	int		count;
	int		*piece_types;
	char	*piece;

	i = 0;
	if ((count = new_lines(content)) == -1)
		errors(1);
	if (count > 26)
		errors(1);
	if (!(piece_types = (int*)malloc(sizeof(int) * count)))
		errors(2);
	while (i < count)
	{
		if (!count_connections(content + 21 * i))
			errors(1);
		piece = peace_maker(content + 21 * i);
		if ((piece_types[i] = peace_checker(piece)) < 0)
			errors(1);
		free(piece);
		i++;
	}
	ft_strdel(&content);
	return (input_is_ok(piece_types, count));
}

int			main(int argc, char **argv)
{
	int			fd;
	char		buf[601];
	int			ret;
	char		*content;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit input_file");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		errors(1);
	if ((ret = read(fd, buf, 600)) < 0)
		errors(1);
	buf[ret] = '\0';
	if (!(content = ft_strdup(buf)))
		errors(2);
	return (validate_file(content));
}
