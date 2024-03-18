#include "ls.h"

/*function to print an error*/
void        print_error(char *err_file)
{
   struct stat sb;

   if (lstat(err_file, &sb) != -1 && access( err_file, R_OK ) == -1)
   {
      ft_putstr("ft_ls: cannot access \'");
      ft_putstr(err_file);
      ft_putendl("\': Permission denied");
   } 
   else if (lstat(err_file, &sb) == -1)
   {
      ft_putstr("ft_ls: cannot access \'");
      ft_putstr(err_file);
      ft_putendl("\': No such file or directory");
   }
}