#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include "../inc/libft.h"

int main(int ac, char **av)
    {
        char *i;
        int c;
        char *s;
        int b;
        char *str = "salut tout le monde";

        s = av[1];
        c = s[0];
        i = av[2];
        b = i[0];
        if((ac - 1) == 0 || (ac - 1) != 3)
            return(0);
        else
        {
            printf("isalpha=""%d\n", isalpha(c));
            printf("ft_isalpha=""%d\n", ft_isalpha(c));
            printf("isdigit=""%d\n", isdigit(c));   
            printf("ft_isdigit=""%d\n", ft_isdigit(c));
            printf("isalnum=""%d\n", isalnum(c));
            printf("ft_isalnum=""%d\n", ft_isalnum(c));
            printf("isascii=""%d\n", isascii(c));
            printf("ft_isascii=""%d\n", ft_isascii(c));
            printf("isprint=""%d\n", isprint(c));
            printf("ft_isprint=""%d\n", ft_isprint(c));
            printf("strlen=""%ld\n", strlen(s));
            printf("ft_strlen=""%ld\n", ft_strlen(s));
            ft_bzero(s, ft_atoi(i));
            printf("ft_bzero= %s\n", s);
            bzero(s, ft_atoi(i));
            printf("bzero= %s\n", s);
            printf("toupper= %d\n", toupper(c));
            printf("ft_toupper= %d\n", ft_toupper(c));
            printf("tolower= %d\n", tolower(c));
            printf("ft_tolower= %d\n", ft_tolower(c));
            printf("strchr= %s\n", strchr(str, 'z'));
            printf("ft_strchr= %s\n", ft_strchr(s, b));
            printf("strrchr= %s\n", strrchr(s, b));
            printf("ft_strrchr= %s\n", ft_strrchr(s, b));
              
        }
    }