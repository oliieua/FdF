/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 17:48:44 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/04/17 16:32:58 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		valid_len(char *file)
{
	t_help	h;

	h.size = 0;
	h.fd = open(file, O_RDONLY);
	get_next_line(h.fd, &h.line);
	h.mas = ft_strsplit(h.line, ' ');
	free(h.line);
	while (h.mas[h.size])
		h.size++;
	ft_free2arr(h.mas);
	while (get_next_line(h.fd, &h.line))
	{
		h.i = 0;
		h.mas = ft_strsplit(h.line, ' ');
		while (h.mas[h.i])
			h.i++;
		free(h.line);
		ft_free2arr(h.mas);
		if (h.i < h.size || h.i > h.size)
			return (0);
	}
	free(h.line);
	return (1);
}

int		check_file(char *file)
{
	int		fd;
	char	arr[0];

	fd = open(file, O_RDONLY);
	if (fd < 0 || (read(fd, arr, 0) < 0))
		return (0);
	return (1);
}

int		correct_symbols(char *file)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		while (line[i])
		{
			if (line[i] == '\t')
			{
				free(line);
				return (0);
			}
			i++;
		}
		free(line);
	}
	free(line);
	return (1);
}

int		empty_file(char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (get_next_line(fd, &line) < 0)
	{
		ft_putendl("No data found.");
		return (0);
	}
	free(line);
	return (1);
}

int		validator(char *file, t_mlx *a)
{
	if (!check_file(file) || !(file_o(file)))
	{
		ft_putendl("Wrong filename.");
		return (0);
	}
	if (!(empty_file(file)))
		return (0);
	ft_countxny(file, a);
	ft_parse(file, a);
	if (a->x_num <= 0)
	{
		ft_putendl("No data found.");
		return (0);
	}
	if (!valid_len(file))
	{
		ft_putendl("Found wrong line length. Exiting.");
		return (0);
	}
	else if (!correct_symbols(file))
	{
		ft_putendl("Found wrong symbols.");
		return (0);
	}
	return (1);
}
