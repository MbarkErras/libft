#include "libft.h"

int	ft_isnumber(char *string)
{
	int i;

	if (!string)
		return (0);
	i = -1;
	while (string[++i])
	{
		if (!ft_isdigit(string[i]))
		{
			if (i == 0 && string[i] == '-')
				continue;
			return (0);
		}
	}
	return (1);
}
