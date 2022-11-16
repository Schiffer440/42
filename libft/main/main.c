#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include "../inc/libft.h"

int main()
    {
        char *str = "salut tout le monde";

            printf("isalpha=""%d\n", isalpha('c'));
            printf("ft_isalpha=""%d\n", ft_isalpha('c'));
            printf("isdigit=""%d\n", isdigit('c'));   
            printf("ft_isdigit=""%d\n", ft_isdigit('c'));
            printf("isalnum=""%d\n", isalnum('c'));
            printf("ft_isalnum=""%d\n", ft_isalnum('c'));
            printf("isascii=""%d\n", isascii('c'));
            printf("ft_isascii=""%d\n", ft_isascii('c'));
            printf("isprint=""%d\n", isprint('c'));
            printf("ft_isprint=""%d\n", ft_isprint('c'));
            printf("strlen=""%ld\n", strlen(str));
            printf("ft_strlen=""%ld\n", ft_strlen(str));
            ft_bzero(str, 3);
            printf("ft_bzero= %s\n", str);
            bzero(str, 3);
            printf("bzero= %s\n", str);
            printf("toupper= %d\n", toupper('c'));
            printf("ft_toupper= %d\n", ft_toupper('c'));
            printf("tolower= %d\n", tolower('c'));
            printf("ft_tolower= %d\n", ft_tolower('c'));
            printf("strchr= %s\n", strchr(str, 'z'));
            printf("ft_strchr= %s\n", ft_strchr(str, 'b'));
            printf("strrchr= %s\n", strrchr(str, 'b'));
            printf("ft_strrchr= %s\n", ft_strrchr(str, 'b'));
              
    }