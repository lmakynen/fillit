/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknuutti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 10:58:20 by jknuutti          #+#    #+#             */
/*   Updated: 2020/02/17 19:59:09 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Checks if all the newlines are in the right places (the input is
** the right size). Also counts how many tetromino pieces we get.
** First if checks the row size. The second if checks the last
** newline and counts how many individual tetromino pieces we have. 
*/

int		new_lines(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n' && i % 5 != (4 + (count % 5)) % 5)
			return (-1);
		i++;
		if (i == 20 + 21 * count)
		{
			count++;
			if (str[i] != '\n' && str[i])
				return (-1);
		}
	}
	if (i != 21 * count - 1)
		return (-1);
	return (count);
}

/*
** Checks if the hash symbols are connected and counts
** how many connections there are. Square is the only
** tetromino which has eight connections. The other
** tetromino pieces have only six connections.
*/

int		count_connections(char *str)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (str[i] == '#')
		{
			if (i - 5 >= 0 && str[i - 5] == '#')
				count++;
			if (i - 1 >= 0 && str[i - 1] == '#')
				count++;
			if (i + 5 < 19 && str[i + 5] == '#')
				count++;
			if (i + 1 < 19 && str[i + 1] == '#')
				count++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

/*
** Makes a string out of the tetromino input.
** The string starts from the first symbol (not dot or \n)
** and contains dots and other symbols (no \n). This way we
** can easily recognize which tetromino we are handling.
*/

char	*peace_maker(char *str)
{
	char	*piece;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(piece = ft_strnew(16)))
		return (NULL);
	while (str[i] == '.' || str[i] == '\n')
		i++;
	while (str[i] && i < 19)
	{
		if (str[i] != '\n')
		{
			piece[j] = str[i];
			j++;
		}
		i++;
	}
	while (j < 16)
	{
		piece[j] = '.';
		j++;
	}
	return (piece);
}

/*
** Compares all the possible tetromino pieces (in the shape
** of a string) to the string we have made of the input. Returns
** us the number of the piece. This way we get to know which
** tetromino we are handling.
*/

int		peace_checker(char *str)
{
	int		i;

	i = -1;
	i += ft_strequ(str, "#...#...#...#...") ? 1 : 0;
	i += ft_strequ(str, "####............") ? 2 : 0;
	i += ft_strequ(str, "##..##..........") ? 3 : 0;
	i += ft_strequ(str, "###...#.........") ? 4 : 0;
	i += ft_strequ(str, "#...#..##.......") ? 5 : 0;
	i += ft_strequ(str, "#...###.........") ? 6 : 0;
	i += ft_strequ(str, "##..#...#.......") ? 7 : 0;
	i += ft_strequ(str, "#.###...........") ? 8 : 0;
	i += ft_strequ(str, "#...#...##......") ? 9 : 0;
	i += ft_strequ(str, "###.#...........") ? 10 : 0;
	i += ft_strequ(str, "##...#...#......") ? 11 : 0;
	i += ft_strequ(str, "##...##.........") ? 12 : 0;
	i += ft_strequ(str, "#..##..#........") ? 13 : 0;
	i += ft_strequ(str, "##.##...........") ? 14 : 0;
	i += ft_strequ(str, "#...##...#......") ? 15 : 0;
	i += ft_strequ(str, "###..#..........") ? 16 : 0;
	i += ft_strequ(str, "#...##..#.......") ? 17 : 0;
	i += ft_strequ(str, "#..##...#.......") ? 18 : 0;
	i += ft_strequ(str, "#..###..........") ? 19 : 0;
	return (i);
}
