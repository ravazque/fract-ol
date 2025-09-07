/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:26:40 by ravazque          #+#    #+#             */
/*   Updated: 2025/09/07 18:18:08 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	skip_whitespace_and_signs(const char **s, int *sign, int *flag)
{
	int	sign_count;

	sign_count = 0;
	while (**s == ' ' || (**s >= 9 && **s <= 13))
		(*s)++;
	while (**s == '+' || **s == '-')
	{
		if (++sign_count > 1)
		{
			*flag = 1;
			return (0);
		}
		if (*((*s)++) == '-')
			*sign = -1;
	}
	return (1);
}

static long	parse_integer_part(const char **s, int *flag)
{
	long	integer_part;

	integer_part = 0;
	while (ft_isdigit(**s))
	{
		if (integer_part > (LONG_MAX / 10) || (integer_part == LONG_MAX / 10
				&& (**s - '0') > LONG_MAX % 10))
		{
			*flag = 1;
			return (0);
		}
		integer_part = (integer_part * 10) + (**s - '0');
		(*s)++;
	}
	return (integer_part);
}

static double	parse_fractional_part(const char **s)
{
	double	fractional_part;
	double	divisor;

	fractional_part = 0.0;
	divisor = 1.0;
	if (**s == '.')
	{
		(*s)++;
		while (ft_isdigit(**s))
		{
			fractional_part = (fractional_part * 10) + (**s - '0');
			divisor *= 10;
			(*s)++;
		}
	}
	return (fractional_part / divisor);
}

double	atodbl(const char *s, int *flag)
{
	int		sign;
	long	integer_part;
	double	fractional_part;

	sign = 1;
	if (!skip_whitespace_and_signs(&s, &sign, flag))
		return (0.0);
	integer_part = parse_integer_part(&s, flag);
	if (*flag)
		return (0.0);
	fractional_part = parse_fractional_part(&s);
	if (*s)
	{
		*flag = 1;
		return (0.0);
	}
	return (sign * (integer_part + fractional_part));
}
