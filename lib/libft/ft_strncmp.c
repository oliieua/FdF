/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:13:43 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/02/08 16:31:31 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	i = 0;
	while (i < n - 1 && p1[i] == p2[i] && p1[i] && p2[i])
		i++;
	if (n == 0)
		return (0);
	return (p1[i] - p2[i]);
}
