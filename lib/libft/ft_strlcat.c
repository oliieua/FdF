/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:33:18 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/02/08 16:31:14 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	m;
	size_t	n;

	n = dstsize;
	i = 0;
	j = 0;
	while (dst[j] && j < dstsize)
		j++;
	m = j;
	while (src[j - m] && m + 1 < n)
	{
		dst[j] = src[j - m];
		j++;
		n--;
	}
	if (m < dstsize)
		dst[j] = '\0';
	return (ft_strlen(src) + m);
}
