/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 15:48:28 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/03/27 21:30:39 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_max_point(t_mlx *a)
{
	int	i;
	int	j;

	i = 0;
	a->max_x = 0;
	a->max_y = 0;
	while (a->y_num > i)
	{
		j = 0;
		while (a->x_num > j)
		{
			if (a->max_x < a->b[i][j].x)
				a->max_x = (int)a->b[i][j].x;
			if (a->max_y < a->b[i][j].y)
				a->max_y = (int)a->b[i][j].y;
			if (a->max_z < a->b[i][j].z)
				a->max_z = (int)a->b[i][j].z;
			j++;
		}
		i++;
	}
}

void	ft_minwrh(t_mlx *a)
{
	if (WIDTH > HEIGHT)
		a->min = HEIGHT;
	else
		a->min = WIDTH;
}

void	ft_max_iso(t_mlx *a)
{
	a->max = 0;
	ft_minwrh(a);
	a->max = a->y_num;
	if (a->x_num > a->y_num)
		a->max = a->x_num;
	else if (a->max < a->max_z)
		a->max = a->max_z;
}

void	ft_max_paralel(t_mlx *a)
{
	a->max = 0;
	ft_minwrh(a);
	a->max = a->y_num;
	if (a->x_num > a->y_num)
		a->max = a->x_num;
}
