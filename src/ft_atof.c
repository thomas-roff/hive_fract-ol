/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:41:06 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/17 15:59:26 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

int	ft_power(int base, int exponent)
{
	int	res;

	res = 1;
	if (exponent == 0)
		return (1);
	while (exponent-- > 0)
		res *= base;
	return (res);
}

float	ft_atof(const char *nptr)
{
	float	res;
	int		integer;
	float	decimal;
	int		i;

	res = 0;
	integer = ft_atoi(nptr);
	decimal = 0.0f;
	i = 0;
	while (ft_isspace((int)*nptr))
		nptr++;
	while (ft_isnum((int)*nptr))
		nptr++;
	if (*nptr == '.' && ft_isdigit((int)nptr[1]))
		nptr++;
	else
		return ((float)integer);
	while (ft_isdigit((int)nptr[i]))
	{
		decimal = (decimal * 10) + (nptr[i] - '0');
		i++;
	}
	decimal /= ft_power(10, i);
	if (integer < 0)
		decimal *= (float)-1;
	res = (float)integer + decimal;
	return (res);
}
