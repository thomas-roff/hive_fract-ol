/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:41:06 by thblack-          #+#    #+#             */
/*   Updated: 2025/10/01 10:59:52 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"
#include <float.h>

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

int	ft_issign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	ft_floatmaxcheck(const char *nptr)
{
	double	res;
	int		digit;

	res = 0.0;
	while (ft_isspace((int)*nptr))
		nptr++;
	if (ft_issign((int)*nptr))
		nptr++;
	while (ft_isdigit((int)*nptr))
	{
		digit = *nptr - '0';
		res = res * 10 + digit;
		if (res > FLT_MAX)
			return (FALSE);
		nptr++;
	}
	return (TRUE);
}

int	ft_naf(const char *nptr)
{
	if (!ft_floatmaxcheck(nptr))
		return (FALSE);
	while (ft_isspace(*nptr))
		nptr++;
	if (ft_issign(*nptr))
		nptr++;
	while (ft_isdigit(*nptr))
		nptr++;
	if (*nptr == '.')
		nptr++;
	while (ft_isdigit(*nptr))
		nptr++;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr)
		return (FALSE);
	else
		return (TRUE);
}

float	ft_big_atof(const char *nptr)
{
	double	res;
	int		digit;
	int		sign;

	res = 0.0;
	sign = 1;
	while (ft_isspace((int)*nptr))
		nptr++;
	if (ft_issign((int)*nptr))
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (ft_isdigit((int)*nptr))
	{
		digit = *nptr - '0';
		res = res * 10 + digit;
		if (res > FLT_MAX)
			return (0.0);
		nptr++;
	}
	return ((float)res * (float)sign);
}

float	ft_atof(const char *nptr)
{
	float	res;
	float	decimal;
	int		i;
	int		j;

	res = ft_big_atof(nptr);
	decimal = 0.0f;
	i = 0;
	j = 0;
	while (ft_isspace((int)nptr[i]))
		i++;
	while (ft_isnum((int)nptr[i]))
		i++;
	if (nptr[i] == '.' && ft_isdigit((int)nptr[i + 1]))
		i++;
	else
		return (res);
	while (ft_isdigit((int)nptr[i + j]))
		decimal = (decimal * 10) + (nptr[i + j++] - '0');
	decimal /= ft_power(10, j);
	if (res < 0)
		decimal *= (float)-1.0;
	res += decimal;
	return (res);
}
