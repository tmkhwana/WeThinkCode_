#include "ls.h"

void        not_empty(t_file_list *file, char *flags, char *file_name)
{
            file = sort_file_list(file, flags, 0);
            if(ft_strchr(flags, 'l'))
                printTotal(file, file_name);
            start_f_print(file, flags, 0);
            write(1, "\n", 1);
            free_file_list(file, 1);
}

/*function to print out the folders*/
void        print_folders(t_file_list *files, char *flags, t_file_list *file)
{
    char        *path;
    struct stat sb;
    t_file_list *temp;

    temp = files;
    while(temp)
    {
        lstat(temp->file, &sb);
        if (S_ISDIR(sb.st_mode))
        {
            path = ft_strjoin(temp->file, "/");
            file = dir_files(temp->file, path, sb, flags, NULL);
            if (file)
            {
                not_empty(file, flags, temp->file);
            }
            free(path);
        }
        temp = temp->next;
    }
}