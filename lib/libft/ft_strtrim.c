/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 18:56:58 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/02/08 16:32:01 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static size_t	ft_frstblnks(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

static size_t	ft_lstblnks(char const *s)
{
	size_t	i;

	i = ft_strlen(s);
	while ((s[i] == ' ' || s[i] == '\n'
	|| s[i] == '\t' || s[i] == '\0') && i)
		i--;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	n;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_frstblnks(s);
	n = ft_lstblnks(s);
	while (j <= n)
	{
		i++;
		j++;
	}
	if (!(str = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	j = ft_frstblnks(s);
	while (j <= n)
		str[i++] = s[j++];
	str[i] = '\0';
	return (str);
}
