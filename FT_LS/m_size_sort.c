#include "ls.h"

/*sort file list according to the size called from the main*/
t_file_list     *msize_file_sort(t_file_list *files)
{
    t_file_list *curr;
    struct stat sbc;
    struct stat sbn;

    curr = files;
    while(curr && curr->next)
    {
        lstat(curr->file, &sbc);
        lstat(curr->next->file, &sbn);
        if (sbc.st_size < sbn.st_size)
        {
            curr = swap(curr);
            curr = files;
        } else
            curr = curr->next;
    }
    return (files);
}

/*sort file list according to the size called from the main*/
t_file_list     *rm_size_file_sort(t_file_list *files)
{       
    t_file_list *curr;
    struct stat sbc;
    struct stat sbn;

    curr = files;
    while(curr && curr->next)
    {
        lstat(curr->file, &sbc);
        lstat(curr->next->file, &sbn);
        if (sbc.st_size > sbn.st_size)
        {
            curr = swap(curr);
            curr = files;
        } else
            curr = curr->next;
    }
    return (files);
}