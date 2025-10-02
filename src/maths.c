/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:13:27 by thblack-          #+#    #+#             */
/*   Updated: 2025/10/01 16:45:54 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

double	ft_sin(double x)
{
	double	term;
	double	sum;
	int		i;

	term = x;
	sum = x;
	i = 1;
	while (i < 10)
	{
		term *= -x * x / ((2 * i) * (2 * i + 1));
		sum += term;
		i++;
	}
	return (sum);
}

double	ft_cos(double x)
{
	double	term;
	double	sum;
	int		i;

	term = 1.0;
	sum = 1.0;
	i = 1;
	while (i < 10)
	{
		term *= -x * x / ((2 * i - 1) * (2 * i));
		sum += term;
		i++;
	}
	return (sum);
}

double	ft_sqrt(double nbr)
{
	double	res;
	int		i;

	res = nbr;
	i = 0;
	if (nbr <= 0)
		return (0);
	while (i < 20)
	{
		res = 0.5 * (res + nbr / res);
		i++;
	}
	return (res);
}

double	ft_atan(double x, double y)
{
	if (x > 0)
		return (y / x);
	if (x < 0 && y >= 0)
		return ((y / x) + 3.14159);
	if (x < 0 && y < 0)
		return ((y / x) - 3.14159);
	if (x == 0 && y > 0)
		return (1.5708);
	if (x == 0 && y < 0)
		return (-1.5708);
	return (0.0);
}
