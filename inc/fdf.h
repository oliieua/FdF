/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macuser <macuser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:13:29 by ooliinyk          #+#    #+#             */
/*   Updated: 2020/03/12 19:58:16 by macuser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H
# define WIDTH 1000
# define HEIGHT 800

# include "../lib/libft/includes/libft.h"
# include "./get_next_line.h"
# include <math.h>
# include <fcntl.h>
# include "../lib/minilibx_macos/mlx.h"

typedef struct	s_point
{
	double			x;
	double			y;
	double			z;
	int				color;
}				t_point;

typedef struct	s_mlx
{
	void		*mlx_p;
	void		*win_p;
	char		*filename;
	double		min;
	int			min_x;
	int			min_y;
	int			max_x;
	int			max_y;
	int			max_z;
	double		distance;
	double		y_p;
	double		x_p;
	int			x_num;
	int			y_num;
	int			max;
	int			points;
	t_point		**b;
}				t_mlx;

typedef struct	s_line
{
	int			x;
	int			y;
	int			i;
	int			j;
	int			color;
	int			move_x;
	double		x0;
	double		x1;
	double		y0;
	double		y1;
	int			deltax;
	int			deltay;
	int			signx;
	int			signy;
	int			err;
	int			err2;
}				t_line;

typedef struct	s_help
{
	int			i;
	int			j;
	int			size;
	int			fd;
	char		*line;
	char		**mas;
}				t_help;

void			iso(double *x, double *y, double z);
void			ft_countxny(char *filename, t_mlx *a);
void			ft_parse(char *filename, t_mlx *a);
void			ft_dots(int i, int j, t_mlx *a, t_line *c);
void			draw_x(int i, int j, t_mlx *a, t_line *c);
void			draw_y(int i, int j, t_mlx *a, t_line *c);
int				ft_close(void *param);
void			isometr(t_mlx *a);
void			x_rotate(double *y, double *z, double alpha);
void			y_rotate(double *x, double *z, double beta);
void			z_rotate(double *x, double *y, double gamma);
int				key_release(int key, t_mlx *a);
int				esc_close(int key, t_mlx *a);
void			ft_max_iso(t_mlx *a);
void			ft_max_paralel(t_mlx *a);
void			fdf_legend_open(t_mlx *a);
int				validator(char *file, t_mlx *a);
void			ft_free2arr(char **arr);
void			projections(int key, t_mlx *a);
void			padding(t_mlx *a);
void			distance(t_mlx *a);
void			ft_max_point(t_mlx *a);
void			usage(void);
void			second_parse(char *filename, t_mlx *a);
int				file_o(char *filename);
void			valid_num(t_help *h);

#endif
