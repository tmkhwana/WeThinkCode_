#include "ls.h"

/*Check if the flag is valid or part of the required -lRart flags*/
char        *valid_flags(char *av, int j)
{
    char 	*str;

    str = ft_strnew(10);
    str[0] = '-';
    while (av[++j])
    {
        if (!(ft_strchr(FLAGS, av[j])))
        {
			ft_putstr("ft_ls: illegal option -- ");
			ft_putchar(av[j]);
			ft_putstr("\nusage: ft_ls [-");
			ft_putstr(FLAGS);
			ft_putendl("] [file ...]");
			exit(0);
		}
        else
            str[j] = av[j];
    }
    str[j] = '\0';
	return (str);
}