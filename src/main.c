/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:47:07 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/04/17 15:34:01 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_dots(int i, int j, t_mlx *a, t_line *c)
{
	draw_x(i, j, a, c);
	draw_y(i, j, a, c);
}

int		file_o(char *filename)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(filename) - 1;
	if (l > 0)
	{
		if (filename[l] == 'o')
			if (filename[l - 1] == '.')
				return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_mlx	a;
	t_line	c;

	if (ac == 2)
	{
		if (validator(av[1], &a))
		{
			c.i = 0;
			c.j = 0;
			a.filename = av[1];
			a.mlx_p = mlx_init();
			a.win_p = mlx_new_window(a.mlx_p, WIDTH, HEIGHT, "FdF");
			isometr(&a);
			fdf_legend_open(&a);
			mlx_hook(a.win_p, 2, 2, key_release, &a);
			mlx_hook(a.win_p, 3, 3, esc_close, &a);
			ft_dots(c.i, c.j, &a, &c);
			mlx_hook(a.win_p, 17, 1L << 17, ft_close, &a);
			mlx_loop(a.mlx_p);
		}
	}
	else
		usage();
	return (0);
}
