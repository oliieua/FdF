/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:31:26 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/03/13 17:18:40 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	fdf_legend_open(t_mlx *a)
{
	mlx_string_put(a->mlx_p, a->win_p, 820, 10, 0x4EF684, "ROTATE X: Q/A");
	mlx_string_put(a->mlx_p, a->win_p, 820, 28, 0x4EF684, "ROTATE Y: W/S");
	mlx_string_put(a->mlx_p, a->win_p, 820, 46, 0x4EF684, "ROTATE Z: E/D");
	mlx_string_put(a->mlx_p, a->win_p, 820, 82, 0x4EF684, "ZOOM: +/-");
	mlx_string_put(a->mlx_p, a->win_p, 820, 118, 0x4EF684, "MOVE UP: UP");
	mlx_string_put(a->mlx_p, a->win_p, 820, 136, 0x4EF684, "MOVE DOWN: DOWN");
	mlx_string_put(a->mlx_p, a->win_p, 820, 154, 0x4EF684, "MOVE LEFT: LEFT");
	mlx_string_put(a->mlx_p, a->win_p, 820, 172, 0x4EF684, "MOVE RIGHT: RIGHT");
	mlx_string_put(a->mlx_p, a->win_p, 820, 208, 0x4EF684, "ISOMETRIC: I");
	mlx_string_put(a->mlx_p, a->win_p, 820, 226, 0x4EF684, "PARALEL: P");
	mlx_string_put(a->mlx_p, a->win_p, 820, 262, 0x4EF684, "EXIT: ESC");
}

void	usage(void)
{
	ft_putendl("usage: ./fdf map_file");
}
