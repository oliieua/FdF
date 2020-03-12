/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotkeys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:02:31 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/04/17 15:58:17 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		ft_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	move_zoom(int key, t_mlx *a)
{
	if (key == 124)
		a->x_p += 8;
	if (key == 123)
		a->x_p -= 8;
	if (key == 125)
		a->y_p += 8;
	if (key == 126)
		a->y_p -= 8;
	if (key == 69 || key == 24)
		a->distance *= 1.1;
	if (key == 78 || key == 27)
		a->distance /= 1.1;
}

void	rotate(int key, t_mlx *a, t_line *c)
{
	while (a->y_num > c->i)
	{
		c->j = 0;
		while (a->x_num > c->j)
		{
			if (key == 13)
				y_rotate(&a->b[c->i][c->j].x, &a->b[c->i][c->j].z, 0.1);
			if (key == 12)
				x_rotate(&a->b[c->i][c->j].y, &a->b[c->i][c->j].z, 0.1);
			if (key == 14)
				z_rotate(&a->b[c->i][c->j].x, &a->b[c->i][c->j].y, 0.1);
			if (key == 1)
				y_rotate(&a->b[c->i][c->j].x, &a->b[c->i][c->j].z, -0.1);
			if (key == 0)
				x_rotate(&a->b[c->i][c->j].y, &a->b[c->i][c->j].z, -0.1);
			if (key == 2)
				z_rotate(&a->b[c->i][c->j].x, &a->b[c->i][c->j].y, -0.1);
			c->j++;
		}
		c->i++;
	}
}

int		esc_close(int key, t_mlx *a)
{
	if (key == 53)
	{
		mlx_destroy_window(a->mlx_p, a->win_p);
		exit(0);
	}
	return (0);
}

int		key_release(int key, t_mlx *a)
{
	t_line	c;

	c.i = 0;
	move_zoom(key, a);
	rotate(key, a, &c);
	projections(key, a);
	mlx_clear_window(a->mlx_p, a->win_p);
	fdf_legend_open(a);
	ft_dots(c.i, c.j, a, &c);
	return (0);
}
