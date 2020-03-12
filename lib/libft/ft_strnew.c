/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 19:41:02 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/02/08 16:31:43 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*s;

	i = 0;
	if (!(s = (char*)malloc(size + 1)))
		return (NULL);
	while (i < size + 1)
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}
