/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:11:29 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/03/27 21:32:25 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	line(t_mlx *a, t_line *c)
{
	c->deltax = fabs(round(c->x1) - round(c->x0));
	c->deltay = fabs(round(c->y1) - round(c->y0));
	c->signx = round(c->x0) < round(c->x1) ? 1 : -1;
	c->signy = round(c->y0) < round(c->y1) ? 1 : -1;
	c->err = c->deltax - c->deltay;
	c->y = round(c->y0);
	c->x = round(c->x0);
	mlx_pixel_put(a->mlx_p, a->win_p, round(c->x1), round(c->y1), c->color);
	while (round(c->x) != round(c->x1) || round(c->y) != round(c->y1))
	{
		mlx_pixel_put(a->mlx_p, a->win_p, c->x, c->y, c->color);
		c->err2 = c->err * 2;
		if ((c->err2) > -c->deltay)
		{
			c->err -= c->deltay;
			c->x += c->signx;
		}
		if ((c->err2) < c->deltax)
		{
			c->err += c->deltax;
			c->y += c->signy;
		}
	}
}

void	isometr(t_mlx *a)
{
	int	i;
	int	j;

	i = 0;
	while (a->y_num > i)
	{
		j = 0;
		while (a->x_num > j)
		{
			iso(&a->b[i][j].x, &a->b[i][j].y, a->b[i][j].z);
			j++;
		}
		i++;
		ft_max_iso(a);
		padding(a);
	}
}

void	projections(int key, t_mlx *a)
{
	if (key == 35)
	{
		second_parse(a->filename, a);
		ft_max_paralel(a);
		padding(a);
	}
	if (key == 34)
	{
		second_parse(a->filename, a);
		isometr(a);
	}
}

void	draw_x(int i, int j, t_mlx *a, t_line *c)
{
	i = 0;
	while (a->y_num > i)
	{
		j = 0;
		if (a->x_num == 1 && a->y_num == 1)
		{
			c->x0 = a->b[i][j].x * a->distance + a->x_p;
			c->y0 = a->b[i][j].y * a->distance + a->y_p;
			c->color = a->b[i][j].color;
			mlx_pixel_put(a->mlx_p, a->win_p, c->x0, c->y0, c->color);
		}
		while (a->x_num > (j + 1))
		{
			c->x0 = a->b[i][j].x * a->distance + a->x_p;
			c->x1 = a->b[i][j + 1].x * a->distance + a->x_p;
			c->y0 = a->b[i][j].y * a->distance + a->y_p;
			c->y1 = a->b[i][j + 1].y * a->distance + a->y_p;
			c->color = a->b[i][j + 1].color;
			line(a, c);
			j++;
		}
		i++;
	}
}

void	draw_y(int i, int j, t_mlx *a, t_line *c)
{
	j = 0;
	while (a->x_num > j)
	{
		i = 0;
		while (a->y_num > (i + 1))
		{
			c->x0 = a->b[i][j].x * a->distance + a->x_p;
			c->x1 = a->b[i + 1][j].x * a->distance + a->x_p;
			c->y0 = a->b[i][j].y * a->distance + a->y_p;
			c->y1 = a->b[i + 1][j].y * a->distance + a->y_p;
			c->color = a->b[i + 1][j].color;
			line(a, c);
			i++;
		}
		j++;
	}
}
