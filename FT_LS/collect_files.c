#include "ls.h"

int             no_dir(char **av)
{
    int         i;
    struct stat sb;

    i = 0;
    while (av[++i])
    {
        if ((av[i][0] != '-' && lstat(av[i], &sb) == -1) || 
            (av[i][0] != '-' && access( av[i], R_OK ) == -1))
            return (0);
    }
    return (1);
}

/*function to get the file names and check if they exist then sort them*/
t_file_list    *collect_files(char **av, int i, t_file_list *head, struct stat *sb)
{
    t_file_list     *curr;

    curr = head;
    while (i-- > 1)
    {
        if (lstat(av[i], sb) != -1 && access( av[i], R_OK ) != -1)
        {
            curr->next = (t_file_list*)malloc(sizeof(t_file_list));
            curr->next->file = ft_strdup(av[i]);
            curr->next->next = NULL;
            curr = curr->next;
        } else if(!(av[i][0] == '-'))
            print_error(av[i]);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
    }
    if(head->next == NULL && no_dir(av))
        curr->file = ft_strdup(".");
    else
    {
        curr = head->next;
        free(head);
    }
    return (curr);
}
