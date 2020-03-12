/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:58:50 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/03/15 18:38:00 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*p1;
	unsigned char	*p2;
	int				i;

	if (!s1 || !s2)
		return (0);
	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	i = 0;
	while (p1[i] == p2[i] && p1[i] && p2[i])
		i++;
	return (p1[i] - p2[i]);
}
