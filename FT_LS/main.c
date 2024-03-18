#include "ls.h"

int 	main(int argc, char **argv)
{
    char          *flags;
    t_file_list   *files;
    struct stat   *sb;

    files = (t_file_list*)malloc(sizeof(t_file_list));
    files->next = NULL;
    sb = (struct stat *)malloc(sizeof(struct stat));
    get_flags(&flags, argv, argc, 0);
    files = collect_files(argv, argc, files, sb);
    files = sort_file_list(files, flags, 1);
    start_print(files, flags);
    if (!ft_strchr(flags, 'l')){
        ft_putendl("");
    }   
    free_file_list(files, 0);
    free(flags);
    free(sb);
    return (0);
}
