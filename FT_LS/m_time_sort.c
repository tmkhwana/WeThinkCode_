#include "ls.h"

/*sort file list according to the last modified time called from main*/
t_file_list     *rm_time_file_sort(t_file_list *files)
{
    t_file_list *curr;
    struct stat sbc;
    struct stat sbn;

    curr = files;
    while(curr && curr->next)
    {
        lstat(curr->file, &sbc);
        lstat(curr->next->file, &sbn);
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
t_file_list     *m_time_file_sort(t_file_list *files)
{
    t_file_list *curr;
    struct stat sbc;
    struct stat sbn;

    curr = files;
    while(curr && curr->next)
    {
        lstat(curr->file, &sbc);
        lstat(curr->next->file, &sbn);
        if (sbc.st_mtime < sbn.st_mtime)
        {
            curr = swap(curr);
            curr = files;
        } else
            curr = curr->next;
    }
    return (files);
}