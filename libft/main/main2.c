#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include <stdlib.h>
#include "../inc/libft.h"

int main(int ac, char **av)
    {
        char *c;
        char *s;
        char *r;

        (void)ac;
        s = av[1];
        r = av[2];
        c = av[3];
        printf("memset=""%p\n", memset(s, (ft_atoi(r) + 48), ft_atoi(c)));
        printf("and = %s\n", s);
        printf("ft_memset=""%p\n", ft_memset(s, (ft_atoi(r) + 48), ft_atoi(c)));
        printf("and = %s\n", s);
        printf("memcpy=""%p\n", memcpy(s, r, ft_atoi(c)));
        printf("and = %s\n", s);
        printf("ft_memcpy=""%p\n", ft_memcpy(s, r, ft_atoi(c)));
        printf("and = %s\n", s);
        printf("memmove=""%p\n", memmove(s, r, ft_atoi(c)));
        printf("and = %s\n", s);
        printf("ft_memmove=""%p\n", ft_memmove(s, r, ft_atoi(c)));
        printf("and = %s\n", s);
        printf("strlcpy=""%ld\n",strlcpy(s, r, ft_atoi(c)));
        printf("and = %s\n", s);
        printf("ft_strlcpy=""%ld\n",ft_strlcpy(s, r, ft_atoi(c)));
        printf("and = %s\n", s);
        printf("ft_strlcat= %ld\n", ft_strlcat(s, r, ft_atoi(c)));
        printf("and = %s\n", s);
        printf("strlcat= %ld\n", strlcat(s, r, ft_atoi(c)));
        printf("and = %s\n", s);
        printf("strncmp= %d\n", strncmp(s, r, atoi(c)));
        printf("ft_strncmp= %d\n", ft_strncmp(s, r, ft_atoi(c)));
    }