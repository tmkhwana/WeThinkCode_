#include "ls.h"

/*To align the columns when long listing*/
void    print_pad(char *str, int str_len, int max_len)
{
    int spaces;

    if (max_len != 0)
    {
        spaces = max_len - str_len;
        while(spaces > 0){
            write(1, " ", 1);
            spaces--;
        }
    }
    write(1, str, str_len);
}