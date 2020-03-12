/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 01:20:19 by macuser           #+#    #+#             */
/*   Updated: 2019/03/05 12:14:26 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	iso(double *x, double *y, double z)
{
	double	x0;
	double	y0;

	x0 = *x;
	y0 = *y;
	*x = (x0 - y0) * cos(0.523599);
	*y = -z + (x0 + y0) * sin(0.523599);
}

void	x_rotate(double *y, double *z, double alpha)
{
	double	y0;
	double	z0;

	y0 = *y;
	z0 = *z;
	*y = y0 * cos(alpha) + z0 * sin(alpha);
	*z = -y0 * sin(alpha) + z0 * cos(alpha);
}

void	y_rotate(double *x, double *z, double beta)
{
	double	x0;
	double	z0;

	x0 = *x;
	z0 = *z;
	*x = x0 * cos(beta) + z0 * sin(beta);
	*z = -x0 * sin(beta) + z0 * cos(beta);
}

void	z_rotate(double *x, double *y, double gamma)
{
	double x0;
	double y0;

	x0 = *x;
	y0 = *y;
	*x = x0 * cos(gamma) + y0 * sin(gamma);
	*y = -x0 * sin(gamma) + y0 * cos(gamma);
}
