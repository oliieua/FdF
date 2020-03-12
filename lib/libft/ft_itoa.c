/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:33:41 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/02/08 16:28:39 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int	ft_cntn(int n)
{
	int i;

	i = 0;
	if (n == -2147483648)
		n += 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0 || n < -2147483648 || n > 2147483647)
		return (1);
	while (n / 10 > 0)
	{
		n /= 10;
		i++;
	}
	if (n > 0)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	int		j;
	char	*str;

	i = ft_cntn(n) - 1;
	j = i + 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(str = (char*)malloc(sizeof(char) * ((j + 1)))))
		return (NULL);
	if (n < 0 && (n *= -1))
		str[0] = '-';
	if (n < 0)
		n *= -1;
	while (n / 10 > 0 && n <= 2147483647)
	{
		str[i--] = (n % 10) + 48;
		n /= 10;
	}
	if (n > 0)
		str[i] = (n % 10) + 48;
	if (n == 0)
		str[0] = '0';
	str[j] = '\0';
	return (str);
}
