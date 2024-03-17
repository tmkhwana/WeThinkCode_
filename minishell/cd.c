#include "minishell.h"


void cd(char *new_path)
{
    char old_path[1024];

    getcwd(old_path, 1024);
    if (chdir(new_path) < 0)
    {
        if (opendir(new_path) == NULL)
        {
            ft_putstr("minishell: cd: ");
            ft_putstr(new_path);
            ft_putendl(": No such file or directory");
        }
        else
            ft_putendl("error changing directory");
    }
    else
    {
        env_setup("PWD", new_path);
        env_setup("OLDPWD", old_path);
    }
}

void pwd()
{
    char dir[1024];

    getcwd(dir, 1024);
    ft_putendl(dir);
}