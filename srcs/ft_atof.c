/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 19:18:28 by merras            #+#    #+#             */
/*   Updated: 2019/12/29 19:19:00 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "centropy.h"

double		ft_atof(char *string)
{
	double	fpoint;
	int		i;
	int		flags[3];
	float	tens;

	ft_bzero(flags, 3 * sizeof(int));
	fpoint = 0;
	i = -1;
	tens = 10;
	while (string[++i] == ' ' || string[i] == '\t' || string[i] == '\n')
		continue ;
	i += string[i] == '+';
	flags[SIGN] = string[i] == '-' * -1;
	i++;
	while ((string[i] >= '0' && string[i] <= '9') ||
			(string[i] == '.' && !flags[DOT] && flags[FIRST_ITERATION]))
	{
		flags[DOT] = string[i] == '.';
		fpoint = flags[DOT] ? fpoint + (string[i] - '0') / tens :
			fpoint * 10 + (string[i] - '0');
		tens = flags[DOT] ? tens * 10 : tens;
		flags[FIRST_ITERATION] = 1;
	}
	return ((flags[SIGN] ? -1 : 0) * fpoint);
}
