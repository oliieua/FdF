/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 21:28:25 by ooliinyk          #+#    #+#             */
/*   Updated: 2018/11/09 21:28:27 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(double *a, double *b)
{
	double	c;

	c = *a;
	*a = *b;
	*b = c;
}
