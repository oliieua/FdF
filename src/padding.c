/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:25:09 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/03/27 22:11:05 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_min_point(t_mlx *a)
{
	int	i;
	int	j;

	i = 0;
	a->min_x = 0;
	a->min_y = 0;
	while (a->y_num > i)
	{
		j = 0;
		while (a->x_num > j)
		{
			if (a->min_x > a->b[i][j].x)
				a->min_x = a->b[i][j].x;
			if (a->min_y > a->b[i][j].y)
				a->min_y = a->b[i][j].y;
			j++;
		}
		i++;
	}
}

void	distance(t_mlx *a)
{
	ft_min_point(a);
	a->distance = (a->min / 2) / a->max;
}

void	padding(t_mlx *a)
{
	ft_max_point(a);
	distance(a);
	a->max_x *= a->distance;
	a->min_x *= a->distance;
	a->max_y *= a->distance;
	a->min_y *= a->distance;
	a->x_p = (WIDTH - a->max_x - a->min_x) / 2;
	a->y_p = (HEIGHT - a->max_y - a->min_y) / 2;
}
