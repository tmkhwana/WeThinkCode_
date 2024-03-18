#include "ls.h"

/*Extracts permissions from file stat*/
char            *get_rwx(struct stat sb)
{
    char *rwx;

    rwx = ft_strnew(10);
    rwx[0] = '-';
    rwx[0] = S_ISBLK(sb.st_mode) ? 'b' : rwx[0];
    rwx[0] = S_ISCHR(sb.st_mode) ? 'c' : rwx[0];
    rwx[0] = S_ISDIR(sb.st_mode) ? 'd' : rwx[0];
    rwx[0] = S_ISLNK(sb.st_mode) ? 'l' : rwx[0];
    rwx[0] = S_ISFIFO(sb.st_mode) ? 'p' : rwx[0];
    rwx[0] = S_ISSOCK(sb.st_mode) ? 's' : rwx[0];
    rwx[1] = sb.st_mode & S_IRUSR ? 'r' : '-';
    rwx[2] = sb.st_mode & S_IWUSR ? 'w' : '-';
    rwx[3] = sb.st_mode & S_IXUSR ? 'x' : '-';
    rwx[4] = sb.st_mode & S_IRGRP ? 'r' : '-';
    rwx[5] = sb.st_mode & S_IWGRP ? 'w' : '-';
    rwx[6] = sb.st_mode & S_IXGRP ? 'x' : '-';
    rwx[7] = sb.st_mode & S_IROTH ? 'r' : '-';
    rwx[8] = sb.st_mode & S_IWOTH ? 'w' : '-';
    rwx[9] = sb.st_mode & S_IXOTH ? 'x' : '-';
    return (rwx); 
}

/*Collects or retrieve a files information */
t_file_info     *collect_info(t_file_info *file, char *name, char *path)
{
    struct stat sb;

    lstat(path, &sb);
    file->file_name = name;
    file->rwx = get_rwx(sb);
    file->links = sb.st_nlink;
    file->user = getpwuid(sb.st_uid)->pw_name;
    file->group = getgrgid(sb.st_gid)->gr_name;
    file->b_size = sb.st_size;
    file->time = ft_strsub(ctime(&sb.st_mtime), 4, 12);
    file->full_name = path;
    return (file);
}