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

int	ft_naf(const char *nptr)
{
	while (ft_isspace(*nptr))
		nptr++;
	if (ft_issign(*nptr))
		nptr++;
	if (!ft_isdigit(*nptr) && *nptr != '.')
		return (FALSE);
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

int	ft_big_atof(const char *nptr, float *nbr)
{
	double	res;
	int		digit;

	res = 0.0;
	if (!ft_naf(nptr))
		return (KO);
	while (ft_isspace((int)*nptr))
		nptr++;
	if (ft_issign((int)*nptr))
		nptr++;
	while (ft_isdigit((int)*nptr))
	{
		digit = *nptr - '0';
		res = res * 10 + (double)digit;
		if (res > FLT_MAX)
			return (KO);
		nptr++;
	}
	*nbr = (float)res;
	return (OK);
}

int	ft_atof(const char *nptr, float	*nbr)
{
	t_float	fl;
	int		i;
	int		sign;

	if (!ft_big_atof(nptr, &fl.whole))
		return (KO);
	fl.dec = 0.0f;
	i = 0;
	sign = 1;
	while (ft_isspace((int)*nptr))
		nptr++;
	if (ft_issign(*nptr))
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (ft_isdigit((int)*nptr))
		nptr++;
	if (*nptr == '.' && ft_isdigit((int)*(nptr + 1)))
		nptr++;
	while (ft_isdigit((int)nptr[i]))
		fl.dec = (fl.dec * 10) + (nptr[i++] - '0');
	*nbr = ((float)fl.whole + (fl.dec / (float)ft_power(10, i))) * (float)sign;
	return (OK);
}
