/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <mbarekerras@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 19:18:28 by merras            #+#    #+#             */
/*   Updated: 2019/12/30 18:18:35 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

double		ft_atof(char *string, int precision)
{
	double	fpoint;
	int		i;
	int		flags[4];
	double	tens;

	ft_bzero(flags, 4 * sizeof(int));
	fpoint = 0;
	i = -1;
	tens = 1;
	while (string[++i] == ' ' || string[i] == '\t' || string[i] == '\n')
		continue ;
	if (string[i] == '+' || string[i] == '-')
	{
		flags[SIGN] = (string[i] == '-') * -1;
		i++;
	}
	while ((string[i] >= '0' && string[i] <= '9') ||
			(string[i] == '.' && !flags[DOT] && flags[FIRST_ITERATION]))
	{
		if (string[i] == '.' && (flags[DOT] = 1))
			continue ;
		flags[PRECISION] += flags[DOT];
		fpoint = flags[DOT] ? fpoint + (string[i] - '0') / tens :
			fpoint * 10 + (string[i] - '0');
		tens = flags[DOT] ? tens * 10 : tens;
		flags[FIRST_ITERATION] = 1;
		if (flags[PRECISION] > precision)
			return (fpoint);
		i++;
	}
	return ((flags[SIGN] ? -1 : 1) * fpoint);
}
