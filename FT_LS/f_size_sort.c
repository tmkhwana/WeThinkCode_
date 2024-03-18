#include "ls.h"

/*function to sort the file list according to the size*/
t_file_list     *size_file_sort(t_file_list *files)
{
    t_file_list *curr;
    struct stat sbc;
    struct stat sbn;

    curr = files;
    while(curr && curr->next)
    {
        lstat(curr->path, &sbc);
        lstat(curr->next->path, &sbn);
        if (sbc.st_size < sbn.st_size)
        {
            swap(curr);
            curr = files;
        } else
            curr = curr->next;
    }
    return (files);
}

/*function to sort the file list according to the size*/
t_file_list     *rsize_file_sort(t_file_list *files)
{
    t_file_list *curr;
    struct stat sbc;
    struct stat sbn;

    curr = files;
    while(curr && curr->next)
    {
        lstat(curr->path, &sbc);
        lstat(curr->next->path, &sbn);
        if (sbc.st_size > sbn.st_size)
        {
            swap(curr);
            curr = files;
        } else
            curr = curr->next;
    }
    return (files);
}