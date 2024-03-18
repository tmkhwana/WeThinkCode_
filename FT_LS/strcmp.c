#include "ls.h"

/*convert uppercases to lowercases b4 comparing. Then compare, see if we need to sort.*/
int		strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && (s1[i] == s2[i]))
	{
		s1++;
		s2++;
	}
	if (((unsigned char)ft_tolower(s1[i]) - 
            (unsigned char)ft_tolower(s2[i])) < 0)
		return (-1);
	else if (((unsigned char)ft_tolower(s1[i]) - 
            (unsigned char)ft_tolower(s2[i])) > 0)
		return (1);
	else
		return (0);
}