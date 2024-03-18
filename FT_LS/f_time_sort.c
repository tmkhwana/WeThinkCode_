#include "ls.h"

t_file_list      *swap(t_file_list *curr)
{
    char        *temp;

    temp = curr->next->file;
    curr->next->file = curr->file;
    curr->file = temp;
    temp = curr->next->path;
    curr->next->path = curr->path;
    curr->path = temp;
    return (curr);
}

/*sort file list according to the last modified time called from main*/
t_file_list     *rtime_file_sort(t_file_list *files)
{
    t_file_list *curr;
    struct stat sbc;
    struct stat sbn;

    curr = files;
    while(curr && curr->next)
    {
        lstat(curr->path, &sbc);
        lstat(curr->next->path, &sbn);
        if (sbc.st_mtime > sbn.st_mtime)
        {
            curr = swap(curr);
            curr = files;
        } else
            curr = curr->next;
    }
    return (files);
}

/*function to sort the file list according to the last modified time*/
t_file_list     *time_file_sort(t_file_list *files)
{
    t_file_list *curr;
    struct stat sbc;
    struct stat sbn;

    curr = files;
    while(curr && curr->next)
    {
        lstat(curr->path, &sbc);
        lstat(curr->next->path, &sbn);
        if (sbc.st_mtime < sbn.st_mtime)
        {
            curr = swap(curr);
            curr = files;
        } else
            curr = curr->next;
    }
    return (files);
}