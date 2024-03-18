#include "ls.h"

int         getMaxLen(t_file_list *files, char *col, int main)
{
    t_file_list     *temp;
    struct stat     sb;
    int             size;
    char            *tmp;

    temp = files;
    size = 0;
    while(temp)
    {
        (main == 0) ? lstat(temp->path, &sb) : lstat(temp->file, &sb);
        if (ft_strequ(col, "link"))
            tmp = ft_itoa(sb.st_nlink);
        if (ft_strequ(col, "size"))
            tmp = ft_itoa(sb.st_size);
        if(ft_strlen(tmp) > size)
            size = ft_strlen(tmp);
        free(tmp);
        temp = temp->next;
    }
    return (size);
}