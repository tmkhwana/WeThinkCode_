#include "ls.h"

/*function to get/retrieve flags*/
void			get_flags(char **line, char **av, int i, int g)
{
	char	*str;
	char	*tmp;
	char	l_str[6];

	while (i-- > 1)
	{
		if (av[i][0] == '-')
		{
			str = valid_flags(av[i], 0);
			tmp = str;
			while (*str != '\0')
			{
				if (!(ft_strchr(l_str, *str)))
					l_str[g++] = *str;
				str++;
			}
			free(tmp);
		}
	}
	l_str[g] = 0;
	*line = ft_strdup(l_str);
}
