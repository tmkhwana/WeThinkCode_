#include "ls.h"

/*function to print out the total when long printing*/
void        printTotal(t_file_list *files, char *dir_name)
{
    int         total;
    struct stat sb;
    t_file_list *temp;

    total = 0;
    ft_putstr(dir_name);
    ft_putstr(":\ntotal  ");
    temp = files;
    while(temp)
    {
        lstat(temp->path, &sb);
        total += sb.st_blocks;
        temp = temp->next;
    }
    ft_putnbr(total);
    ft_putendl("");
}