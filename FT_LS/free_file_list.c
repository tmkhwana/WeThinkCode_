#include "ls.h"

/*function to free the list of files we created in collect_files*/
void        free_file_list(t_file_list *file_head, int path)
{
    t_file_list *curr;

    curr = file_head;
    while (curr)
    {
        curr = curr->next;
        free(file_head->file);
        if (path)
            free(file_head->path);
        free(file_head);
        file_head = curr;
    }
}