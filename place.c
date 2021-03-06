/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <jfleisch@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 15:43:30 by jfleisch          #+#    #+#             */
/*   Updated: 2018/05/06 15:46:10 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdio.h>

/*
**	tet_x_shift() iterates through the first row of the tetris shape
**	moving to the next spot as long as it is a '.'
**	the number of '.' found is returned
*/
int					tet_x_shift(t_etris *tetris)
{
	int				x_shift;

	x_shift = 0;
	while ((tetris->shape)[0][x_shift] == '.')
		x_shift++;
	return (x_shift);
}

/*
**	check_tet_max()	compares the tetris height
**	and the width - the return from tet_x_shift() to map dim
**	if both or <= the dim then it returns (1) otherwise it returns (0)
*/
int				check_tet_max(t_etris *tetris, t_map *map, t_point *point)
{
	if ((point->y + tetris->height <= (int)map->size)
		&& (point->x - tet_x_shift(tetris) + tetris->width <= (int)map->size))
		return (1);
	ft_putendl("\ncheck_tet_max returned 0");
	return (0);
}

// void 			free_tetris(t_etris *tetris)
// {
//
// }

/*
**	tet_place() iterates through the shape setting the board pos to the
**	tetris_shape pos if it != '.' then goes to the next pos
**	if the map pos is a new line the x %= the map dim and the y++
*/
void 			tet_place(t_etris* tetris, t_map *map, t_point *point)
{
	int			y;
	int			x;
	char		**board;
	char		**tetris_shape;

	y = -1;
	board = map->rows;
	tetris_shape = tetris->shape;
	while (tetris_shape[++y] != NULL)
	{
		x = -1;
		while (tetris_shape[y][++x] != '\0')
		{
			if (tetris_shape[y][x] != '.')
				board[map->c + point->y][map->r - tet_x_shift(tetris) + point->x]
				= tetris_shape[y][x];
		}
	}
	// tetris->first->x = (point->x) - tet_x_shift(tetris);
	// tetris->first->y = point->y;
}

/*
**	tet_remove() iterates throught the shape setting the board pos to
**	'.'	if the tetris_shape != '.'
*/
void 			tet_remove(t_etris* tetris, t_map *map)
{
	int			y;
	int			x;
	//int			col;
	//int			row;
	char		**tetris_shape;

	y = -1;
//	col = 0;
	tetris_shape = tetris->shape;
	while (tetris_shape[++y] != NULL)
	{
		//row = 0;
		x = -1;
		while (tetris_shape[y][++x] != '\0')
		{
			if (tetris_shape[y][x] != '.')
				map->rows[map->c + tetris->first->y][map->c + tetris->first->x] = '.';
		}
		//col++;
	}
}
