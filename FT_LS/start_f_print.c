#include "ls.h"

/*function to print folders*/
void        start_f_print(t_file_list *files, char *flags, int size)
{
    t_file_list     *temp;
    t_file_info     *file;
    int             link;
    
    temp = files;
    link = getMaxLen(files, "link", 0);
    size = getMaxLen(files, "size", 0);
    while(temp)
    {
        if (ft_strchr(flags, 'l'))
        {
            file = (t_file_info *)malloc(sizeof(t_file_info));
            file = collect_info(file, temp->file, temp->path);
            long_print(file, size, link);
            free_info(file);
        } else
        {
            ft_putstr(temp->file);
            ft_putstr("  ");
        }
        temp = temp->next;
    }
}