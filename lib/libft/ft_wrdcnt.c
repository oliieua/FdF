/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrdcnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:38:40 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/02/08 16:32:08 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_wrdcnt(char const *s, char c)
{
	int	i;
	int	j;

	if (!s || !c)
		return (0);
	i = 0;
	j = 0;
	if (ft_strlen(s) == 0)
		return (0);
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c))
			j++;
		i++;
	}
	if (s[i - 1] != c)
		j++;
	return (j);
}
