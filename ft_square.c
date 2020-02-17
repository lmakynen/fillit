/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknuutti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:45:19 by jknuutti          #+#    #+#             */
/*   Updated: 2020/02/17 19:57:51 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Counts the size of our output 'box'. Count is the
** amount of the pieces we get. We multipy that by four
** because there's always four hash symbols. This size
** will be the minimum size where all the tetromino
** pieces fit. 
*/

int		ft_square(int count)
{
	int		i;

	i = 0;
	while (!(i * i >= count * 4))
		i++;
	return (i);
}
