/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 03:00:10 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/02/08 16:31:49 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;

	i = ft_strlen(s);
	j = 0;
	while (i >= j)
	{
		if (s[i] == c)
			return ((char*)&s[i]);
		i--;
	}
	if (c == '\0')
		return ((char*)&s[i]);
	return (NULL);
}
