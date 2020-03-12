/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 21:05:36 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/02/08 16:31:55 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char*)&haystack[0]);
	while (haystack[i] != '\0' && (ft_strlen(haystack) >= ft_strlen(needle)))
	{
		while (haystack[i] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char*)&haystack[i - j]);
			j++;
			i++;
		}
		i = i - j + 1;
		j = 0;
	}
	return (NULL);
}
