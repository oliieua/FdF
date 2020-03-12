/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:07:32 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/02/08 16:49:34 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

static char	*ft_fndntr(char *str)
{
	char	*dstfrst;
	char	*dst;
	char	*strfrst;

	if (!str)
		return (NULL);
	strfrst = str;
	while (*str != '\n' && *str)
		str++;
	if (!(dst = ft_strnew(str - strfrst)))
		return (NULL);
	dstfrst = dst;
	while (*strfrst != '\n' && *strfrst)
		*dst++ = *strfrst++;
	return (dstfrst);
}

static char	*ft_after(char *str)
{
	char	*strfrst;
	char	*dst;
	char	*dstfrst;
	char	*strfr;

	strfr = str;
	strfrst = str;
	while (*str)
	{
		if (*str == '\n')
		{
			str++;
			break ;
		}
		str++;
	}
	while (*strfrst)
		strfrst++;
	if (!(dst = ft_strnew(strfrst - str)))
		return (NULL);
	dstfrst = dst;
	while (*str)
		*dst++ = *str++;
	free(strfr);
	return (dstfrst);
}

int			get_next_line(int fd, char **line)
{
	char		cache[BUFF_SIZE + 1];
	static char	*str[0];
	char		*tmp;
	int			ret;

	if (fd < 0 || BUFF_SIZE < 1 || line == NULL || (read(fd, cache, 0) < 0))
		return (-1);
	while ((ret = read(fd, &cache, BUFF_SIZE)))
	{
		cache[ret] = '\0';
		tmp = str[fd];
		str[fd] = ft_strjoin(str[fd], cache);
		free(tmp);
		if (ft_strchr(cache, '\n'))
			break ;
	}
	if (!(*line = ft_fndntr(str[fd])))
		return (-1);
	if (ret == 0 && (ft_strcmp(str[fd], "") == 0))
		return (0);
	str[fd] = ft_after(str[fd]);
	return (1);
}
