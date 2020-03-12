/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:14:06 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/04/17 15:57:15 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_free2arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	second_parse(char *filename, t_mlx *a)
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	char	**mas;

	i = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		j = 0;
		mas = ft_strsplit(line, ' ');
		free(line);
		while (mas[j])
		{
			a->b[i][j].y = i;
			a->b[i][j].x = j;
			a->b[i][j].z = ft_atoi(mas[j]);
			a->b[i][j].color = 0x4EF684;
			j++;
		}
		ft_free2arr(mas);
		i++;
	}
	free(line);
}

void	ft_countxny(char *filename, t_mlx *a)
{
	char	*line;
	char	**mas;
	int		fd;

	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		mas = ft_strsplit(line, ' ');
		free(line);
		a->y_num++;
		while (mas[a->x_num])
			a->x_num++;
		ft_free2arr(mas);
	}
	free(line);
}

void	valid_num(t_help *h)
{
	if (ft_strlen(h->mas[h->j]) > 10)
	{
		ft_putendl("Wrong num length");
		exit(0);
	}
}

void	ft_parse(char *filename, t_mlx *a)
{
	t_help	h;

	h.i = 0;
	h.fd = open(filename, O_RDONLY);
	a->b = (t_point **)malloc(sizeof(t_point *) * a->y_num);
	while (get_next_line(h.fd, &h.line))
	{
		h.j = 0;
		h.mas = ft_strsplit(h.line, ' ');
		a->b[h.i] = (t_point *)malloc(sizeof(t_point) * a->x_num);
		free(h.line);
		while (h.mas[h.j])
		{
			a->b[h.i][h.j].y = h.i;
			a->b[h.i][h.j].x = h.j;
			valid_num(&h);
			a->b[h.i][h.j].z = ft_atoi(h.mas[h.j]);
			a->b[h.i][h.j].color = 0x4EF684;
			h.j++;
		}
		ft_free2arr(h.mas);
		h.i++;
	}
	free(h.line);
}
