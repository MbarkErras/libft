/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merras <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 21:03:06 by merras            #+#    #+#             */
/*   Updated: 2019/08/02 19:29:38 by merras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		array_length(char **array)
{
	int i;

	if (!array)
		return (0);
	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

void	print_array(char **array)
{
	int i;

	i = -1;
	if (!array)
		return ;
	while (array[++i])
		printf("[%s]\n", array[i]);
		//ft_putendl(array[i]);
}
