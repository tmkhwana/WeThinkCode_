#include "ls.h"

/*function to free the information retrieved in collect_info*/
void        free_info(t_file_info *file_head)
{
    free(file_head->time);
    free(file_head->rwx);
    free(file_head);
}