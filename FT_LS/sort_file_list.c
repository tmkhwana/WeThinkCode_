#include "ls.h"

t_file_list     *main_sort(t_file_list *files, char *flags)
{
    if (ft_strchr(flags, 't'))
    {
        if(ft_strchr(flags, 'r'))
            return (rm_time_file_sort(files));
        else
            return (time_file_sort(files));
    }else if(ft_strchr(flags, 'S'))
    {
        if(ft_strchr(flags, 'r'))
            return (rm_size_file_sort(files));
        else
            return (size_file_sort(files));
    }else if(ft_strchr(flags, 'r'))
    {
        return (desc_file_sort(files));
    } else 
    {
        return (asc_file_sort(files));
    }
}

t_file_list     *folder_sort(t_file_list *files, char *flags)
{
    if (ft_strchr(flags, 't'))
    {
        if(ft_strchr(flags, 'r'))
            return (rtime_file_sort(files));
        else
            return (time_file_sort(files));
    }else if(ft_strchr(flags, 'S'))
    {
        if(ft_strchr(flags, 'r'))
            return (rsize_file_sort(files));
        else
            return (size_file_sort(files));
    }else if(ft_strchr(flags, 'r'))
    {
        return (desc_file_sort(files));
    } else 
    {
        return (asc_file_sort(files));
    }
}

t_file_list     *sort_file_list(t_file_list *files, char *flags, int main)
{
    if (main == 1)
    {
        return (main_sort(files, flags));
    }
    else
    {
        return (folder_sort(files, flags));
    }
}