/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:41:37 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/02/08 16:28:14 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long int	n;
	int					m;

	i = 0;
	n = 0;
	m = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		m = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - 48);
		if (n >= 9223372036854775807 && m == 1)
			return (-1);
		else if (n > 9223372036854775807 && m == -1)
			return (0);
		i++;
	}
	return (m * n);
}
