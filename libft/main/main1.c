#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include <stdlib.h>
#include "../inc/libft.h"

int main(int ac, char **av)
{
    if(ac == 0)
        return(0);
    else
        printf("ft_strjoin=%s\n", ft_strjoin(av[1], av[2]));
}