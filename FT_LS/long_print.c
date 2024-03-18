#include "ls.h"

void    print_link(char *path)
{
    struct stat sb;
    char        *link;

    lstat(path, &sb);
    if (S_ISLNK(sb.st_mode))
    {
        link = ft_strnew(255);
        readlink(path, link, 255);
        ft_putstr(" -> ");
        ft_putstr(link);
        free(link);
    }
}

/*function to print files in a long format*/
void    long_print(t_file_info *file, int s_size, int s_link)
{
    char    *links;
    char    *size;

    links = ft_itoa(file->links);
    size = ft_itoa(file->b_size);
    print_pad(file->rwx, ft_strlen(file->rwx), 0);
    write(1, "  ", 2);
    print_pad(links, ft_strlen(links), s_link);
    write(1, "  ", 2);
    print_pad(file->user, ft_strlen(file->user), 0);
    write(1, "  ", 2);
    print_pad(file->group, ft_strlen(file->group), 0);
    write(1, "  ", 2);
    print_pad(size, ft_strlen(size), s_size);
    write(1, "  ", 2);
    print_pad(file->time, ft_strlen(file->time), 0);
    write(1, "  ", 2);
    print_pad(file->file_name, ft_strlen(file->file_name), 0);
    print_link(file->full_name);
    write(1, "\n", 1);
    free(links);
    free(size);
}