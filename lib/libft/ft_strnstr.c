/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:20:07 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/02/08 16:31:46 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char*)&haystack[0]);
	while (haystack[i] && (ft_strlen(haystack) >= ft_strlen(needle)) && i < len)
	{
		while (haystack[i] == needle[j] && i < len)
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
