#include "ls.h"

/*function to print out regular files*/
void        print_r_files(char *filename, char *flags, char *path, int s, int l)
{
    t_file_info     *file;

    file = (t_file_info *)malloc(sizeof(t_file_info));
    if (ft_strchr(flags, 'l'))
    {
        file = collect_info(file, filename, path);
        long_print(file, s, l);
    } else
    {
        ft_putstr(filename);
        ft_putstr("  ");
    }
    free_info(file);
}