#include "ls.h"

t_file_list         *createNext(char *name, char *full_path, t_file_list *curr)
{
    t_file_list *next;

    next = (t_file_list *)malloc(sizeof(t_file_list));
    next->file = ft_strdup(name);
    next->path = ft_strdup(full_path);
    curr->next = next;
    free(full_path);
    return (curr->next);
}

/*takes a path to a directory*/
t_file_list         *dir_files(char *path, char *fpath, struct stat sb, char *flags, char *full_path)
{
    DIR             *dir_inf;
	struct dirent	*dir;
    t_file_list     *file;
    t_file_list     *curr;
    
    file = (t_file_list *)malloc(sizeof(t_file_list));
    file->next = NULL;
    dir_inf = opendir(path);
    curr = file;
    while((dir = readdir(dir_inf)) != NULL)
        if (access( dir->d_name, R_OK ) != -1 && !ft_strchr(flags, 'a') && dir->d_name[0] == '.')
            continue;
        else
        {
            full_path = ft_strjoin(fpath, dir->d_name);
            if (lstat(full_path, &sb) != -1 && access(full_path, R_OK ) != -1)
                curr = createNext(dir->d_name, full_path, curr);
            else
                print_error(dir->d_name);
        }
    free(dir_inf);
    curr = (file->next) ? file->next : NULL;
    free(file);
    return (curr);
}