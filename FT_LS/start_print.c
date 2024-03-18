#include "ls.h"

void        start_print(t_file_list *files, char *flags)
{
    t_file_list     *temp;
    struct stat     sb;
    t_file_list     *file;
    int             link;
    int             size;

    link = getMaxLen(files, "link", 1);
    size = getMaxLen(files, "size", 1);
    file = NULL;
    temp = files;
    while(temp)
    {
        lstat(temp->file, &sb);
        if (!S_ISDIR(sb.st_mode)){
            print_r_files(temp->file, flags, temp->file, size, link);
        }
        temp = temp->next;
    }
    print_folders(files, flags, file);
}